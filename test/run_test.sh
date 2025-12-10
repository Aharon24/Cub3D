#!/bin/bash
# Перейти в корень проекта (где лежит cub3D и папка test)
cd "$(dirname "$0")/.."

echo "Running Cub3D tests..."
python3 -m pytest test/ -v
exit $?
