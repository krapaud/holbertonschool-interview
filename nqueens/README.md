# N Queens

## Description

Program that solves the N queens puzzle: placing N non-attacking queens on an N×N chessboard.

## Usage

```bash
./0-nqueens.py N
```

## Example

```bash
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

## Algorithm

Uses **backtracking**: queens are placed row by row. For each row, every column is tried. If a position is safe (no queen on same column or diagonal), the queen is placed and we move to the next row. If no position works, we backtrack.
