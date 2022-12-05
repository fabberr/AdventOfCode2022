#include <filesystem>
#include <fstream>

#include "fmt/format.h"
#include "fmt/ranges.h"

void part1(std::ifstream& input) {
}

void part2(std::ifstream& input) {
}

/**
 * https://adventofcode.com/2022/day/
 * 
 * Usage: ./day00 [input-file]
*/
int main(const int argc, const char** argv) {
    namespace fs = std::filesystem;

    const auto filename = argc <= 1 ? "./input.txt" : argv[1];
    std::ifstream input{filename};

    const auto solve = (not fs::exists("./pt1.answer")) ? &part1 : &part2;
    solve(input);
}
