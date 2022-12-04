#include <fstream>

#include "fmt/format.h"
#include "fmt/ranges.h"

/**
 * https://adventofcode.com/2022/day/
 * 
 * Usage: ./day00 [input-file]
*/
int main(const int argc, const char** argv) {
    const auto filename = argc <= 1 ? "./input.txt" : argv[1];
    std::ifstream input{filename};

    for (std::string moves; getline(input, moves); ) {
        // ...
    }
    // fmt::print("{}\n", answer);
}
