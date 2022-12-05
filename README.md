# Advent of Code 2022

My solutions for the [Advent of Code 2022](https://adventofcode.com/2022/about) [puzzles](https://adventofcode.com/2022), implemented in C++.

Code for each solution is under the `src/` directory, sorted by day.

## Installing Dependencies

You'll need `make`, [`{fmt}`](https://github.com/fmtlib/fmt) and a C++20-capable compiler to build the solutions in this repo.
You can install the latest versions of all dependencies using [Homebrew](https://brew.sh).

Start by installing the Homebrew package manager if you don't have it already:

`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`

You can then install all dependencies with the `brew` command:

`brew update && brew install gcc@12 make fmt`

## Building and Solving
To build a solution, `cd` into its source directory and simply run `make`.

A `make run` target is also provided for running the solutions right away. Forwarding arguments to the solution through this target can be done by setting an environment variable like such: `make run args='<arg-list>'`. For usage of a specific solution, check the comment block just above the main function in its source file.

Once the correct solution for part one of a puzzle is found, create a file named `pt1.answer` in the solution's source directory (i.e. `make run > pt1.answer`), any subsequent runs of this solution will execute code to solve the puzzle for part two instead. Deleting the file reverts this behavior.

### Debugging with Visul Studio Code:
Provided in the `.vscode/` directory are the necessary configuration files for building and debugging a solution using Visual Studio Code's integrated debugging tools.

For debugging with VSCode:
- Open the solution's source code in the editor.
- ***Build it with `Ctrl + Shift + B`*** (this will build the current file with <ins>debug symbols present and compiler optimizations turned off</ins>).
- Add a breakpoint and launch the debugger with `F5`.

  <sup>Note: If you'd like to build and debug the solutions independently, check the [tasks.json](https://github.com/fabberr/AdventOfCode2022/blob/master/.vscode/tasks.json#L7) file and make sure you pass the same args to the compiler when building.</sup>
