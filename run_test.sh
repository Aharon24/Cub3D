#!/bin/bash
# run_tests.sh — запуск тестов для Cub3D

# Перейти в корень проекта (где лежит cub3D и папка test)
cd "$(dirname "$0")" || { echo "Failed to cd to project root"; exit 1; }

# Проверяем, что папка test существует
if [ ! -d "./test" ]; then
    echo "Error: test folder not found!"
    exit 1
fi

echo "Running Cub3D tests..."

# Запускаем Python-тесты
python3 test/test_file.py

# Возвращаем код выхода последней команды
exit $?
