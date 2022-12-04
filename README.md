# Advent of Code 2022

My solutions for the [Advent of Code 2022](https://adventofcode.com/2022/about) [puzzles](https://adventofcode.com/2022), implemented in C++.

## Installing Dependencies

You'll need `make`, [`{fmt}`](https://github.com/fmtlib/fmt) and a C++20-capable compiler to build the solutions in this repo.
You can install the latest versions of all dependencies using [Homebrew](https://brew.sh).

Start by installing the Homebrew package manager if you don't have it already:

`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`

You can then install all dependencies with the `brew` command:

`brew update && brew install gcc@12 make fmt`

## Building
To build each solution, navigate to their respective directories (i.e. `cd src/day01`) and simply run `make`.
A `make run` target is also provided for running the built executables right away.
