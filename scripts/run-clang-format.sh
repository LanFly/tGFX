#!/bin/sh

clang_format_executable="clang-format"

if command -v clang-format-9 > /dev/null; then
  clang_format_executable=clang-format-9
fi

if command -v clang-format-10 > /dev/null; then
  clang_format_executable=clang-format-10
fi

${clang_format_executable} --version

./scripts/run-clang-format.py --clang-format-executable ${clang_format_executable} -r include src examples
