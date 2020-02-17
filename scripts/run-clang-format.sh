#!/bin/sh

clang-format --version

./scripts/run-clang-format.py -r include src examples
