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

tests_file  = [
    ([], True, "No arguments"),                       # Run without any arguments
    (["t.cub", "another.cub"], True, "Multiple files given"),  # Run with multiple files
    (["t.fsf.cub"], True, "File does not exist"),    # Nonexistent file
    (["t.cub"], True, "File exists but no access"),  # File exists but no read permission
]

print("Running Cub3D tests...\n")

for i, (args, should_fail, description) in enumerate(tests_file, 1):
    result = subprocess.run([CUB3D] + args, capture_output=True, text=True)
    output = result.stdout + result.stderr
    passed = (("Error" in output) if should_fail else ("Error" not in output))
    status = f"{GREEN}ok{RESET}" if passed else f"{RED}ko{RESET}"
    print(f"{i} -> {description.ljust(30)} {status}")

print("\nAll tests done.")
