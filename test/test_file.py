#!/usr/bin/env python3
import subprocess
import os
import sys

# Путь к cub3D
CUB3D = os.path.join(os.path.dirname(__file__), "..", "cub3D")
CUB3D = os.path.abspath(CUB3D)

# Цвета
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

# Проверяем: включать ли Valgrind
USE_VALGRIND = False
if len(sys.argv) > 1 and sys.argv[1] == "valgrind":
    USE_VALGRIND = True
    print("Valgrind mode ENABLED\n")
else:
    print("Normal mode (no Valgrind)\n")


# Папки с тестовыми картами
test_folders = [
    "map_for_test/map_all_wrnog",
    "map_for_test/map_wrong_F_C",
    "map_for_test/map_part_moving"
]

# Собираем все файлы
tests_file = []
for folder in test_folders:
    folder_path = os.path.join(os.path.dirname(__file__), folder)
    folder_path = os.path.abspath(folder_path)
    if not os.path.exists(folder_path):
        print(f"Warning: folder not found: {folder_path}")
        continue

    for file_name in os.listdir(folder_path):
        file_path = os.path.join(folder_path, file_name)
        tests_file.append(file_path)


print("Running Cub3D tests...\n")

for i, file_path in enumerate(tests_file, 1):


    result = subprocess.run([CUB3D, file_path], capture_output=True, text=True)
    output = result.stdout + result.stderr

    has_error = ("Error" in output)


    has_valgrind_error = False

    if USE_VALGRIND:
        val_cmd = [
            "valgrind",
            "--error-exitcode=42",
            CUB3D,
            file_path
        ]
        v_run = subprocess.run(val_cmd, capture_output=True, text=True)
        if v_run.returncode == 42:
            has_valgrind_error = True



    passed = has_error or has_valgrind_error
    status = GREEN + "ok" + RESET if passed else RED + "ko" + RESET

    print(f"{i} -> {os.path.basename(file_path).ljust(40)} {status}")

    if not passed:
        print(f"Output:\n{output}\n")
        if USE_VALGRIND:
            print("Valgrind output:\n", v_run.stderr)
            print()


print("\nAll tests done.")
