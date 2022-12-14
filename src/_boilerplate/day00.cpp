#include <filesystem>
namespace fs = std::filesystem;

#include <fstream>
#include <string_view>

#include "fmt/format.h"
#include "fmt/ranges.h"

/** Solution for part one of the puzzle. */
void part1(std::ifstream& input) {
    input.close();
}

/** Solution for part two of the puzzle. */
void part2(std::ifstream& input) {
    input.close();
}

/**
 * https://adventofcode.com/2022/day/
 * 
 * Usage: ./day00 [input-file]
*/
int main(const int argc, const char** argv) {

    const auto filename = (argc > 1 and fs::is_regular_file(argv[1])) ? argv[1] : "./input.txt";
    if (fs::is_empty(filename)) { return EXIT_FAILURE; }
    std::ifstream input{filename};

    const auto solve = (not fs::exists("./pt1.answer")) ? &part1 : &part2;
    solve(input);
}
