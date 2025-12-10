#!/usr/bin/env python3
import subprocess
import os

# Пусть к cub3D
CUB3D = os.path.join(os.path.dirname(__file__), "..", "cub3D")
CUB3D = os.path.abspath(CUB3D)

# Цвета ANSI
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

# Папки с тестами (относительно этого файла)
test_folders = [
    "map_for_test/map_all_wrnog",
    "map_for_test/map_wrong_F_C"
]

# Собираем все файлы из папок
tests_file = []
for folder in test_folders:
    folder_path = os.path.join(os.path.dirname(__file__), folder)
    folder_path = os.path.abspath(folder_path)
    
    if not os.path.exists(folder_path):
        print(f"Warning: folder not found: {folder_path}")
        continue

    for file in os.listdir(folder_path):
        file_path = os.path.join(folder_path, file)
        # Определяем, что тест должен провалиться
        fail_keywords = ["no_access", "wrong", ".txt", "empty"]
        should_fail = any(k in file for k in fail_keywords)
        tests_file.append(([file_path], should_fail, file))

print("Running Cub3D tests...\n")

for i, (args, should_fail, description) in enumerate(tests_file, 1):
    result = subprocess.run([CUB3D] + args, capture_output=True, text=True)
    output = result.stdout + result.stderr
    passed = (("Error" in output) if should_fail else ("Error" not in output))
    status = f"{GREEN}ok{RESET}" if passed else f"{RED}ko{RESET}"
    print(f"{i} -> {description.ljust(40)} {status}")
    if not passed:
        print(f"Output:\n{output}\n")

print("\nAll tests done.")
