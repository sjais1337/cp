#!/bin/bash

TEMPLATE_PATH="$HOME/dsa/usaco.cpp"
PROBLEM_NAME="$1"
PROBLEM_CODE="$2"

if [ -z "$PROBLEM_NAME" ]; then
    echo "Usage: gen <problem_name> <problem_code>" 
    exit 1
fi

cp "$TEMPLATE_PATH" "${PROBLEM_CODE}.cpp"

sed -i "/int main/a \\
    freopen(\"${PROBLEM_NAME}.in\", \"r\", stdin);\\
    freopen(\"${PROBLEM_NAME}.out\", \"w\", stdout);" "${PROBLEM_CODE}.cpp"

touch "${PROBLEM_NAME}.in"

code -r "${PROBLEM_NAME}.in" "${PROBLEM_CODE}.cpp"