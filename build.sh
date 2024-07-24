#!/bin/bash

set -xe

clang -Wall -Wextra -o rps rps.c nn.c -lm

