# Menger Sponge

## Description

This project implements a 2D version of the Menger Sponge fractal pattern in C.

## How it works

A level N Menger Sponge is a 3x3 grid of level N-1 sponges, where the center block is left empty.

- Level 0: a single `#` character
- Level 1: a 3x3 grid with the center empty
- Level N: size is `3^N`

A cell at position `(row, col)` is empty if at any subdivision level `k`, both `(row / 3^k) % 3 == 1` and `(col / 3^k) % 3 == 1`.

## Usage

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
./0-menger <level>
```

## Examples

```
$ ./0-menger 0
#
$ ./0-menger 1
###
# #
###
$ ./0-menger 2
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```
