# skyscraperSolver

A command-line program that solves skyscraper puzzles of different sizes.

## How to start

```sh
make
./skyscraper "4 1 2 3 1 2 2 2 2 2 2 1 3 2 1 4"
```

The input contains four clues for every row or column of the board. For a
board of size `N`, provide `4 * N` clues in this order:

1. Columns viewed from the top
2. Columns viewed from the bottom
3. Rows viewed from the left
4. Rows viewed from the right

Each clue must be between `1` and `N`. Any non-digit character can be used as a separator between clues.

## Test boards

The following valid test cases cover board sizes from 1x1 to 8x8. The larger
boards are useful for benchmarking the backtracking solver.

### 1x1

```sh
./skyscraper "1 1 1 1"
```

### 2x2

```sh
./skyscraper "2 1 1 2 2 1 1 2"
```

### 3x3

```sh
./skyscraper "3 2 1 1 2 2 3 2 1 1 2 2"
```

### 4x4

```sh
./skyscraper "4 1 2 3 1 2 2 2 2 2 2 1 3 2 1 4"
```

### 5x5

```sh
./skyscraper "2 2 1 2 3 2 1 4 4 3 3 4 4 1 2 3 2 1 2 2"
```

### 6x6

```sh
./skyscraper "4 1 2 3 4 2 1 3 3 2 2 2 2 3 3 2 3 1 4 4 1 2 3 2"
```

### 7x7

```sh
./skyscraper "2 3 2 4 3 1 3 3 2 1 3 4 3 3 4 1 3 3 4 2 3 2 4 2 2 1 3 3"
```

### 8x8

```sh
./skyscraper "2 4 3 4 4 2 1 3 3 3 3 2 1 2 5 4 5 1 4 4 3 2 4 3 2 2 1 2 3 3 3 3"
```

### Benchmark

To benchmark a test case use can use the `time` command as so:

```sh
time ./skyscraper "2 3 2 4 3 1 3 3 2 1 3 4 3 3 4 1 3 3 4 2 3 2 4 2 2 1 3 3"
51.30s user 0.01s system 99% cpu 51.309 total
```
