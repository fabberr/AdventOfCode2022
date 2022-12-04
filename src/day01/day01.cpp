#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <span>
#include <cstddef>

#include "fmt/format.h"
#include "fmt/ranges.h"

// read calories values until empty line is found, return the sum
int sum_next(std::ifstream& input) {
    auto sum = 0;
    for (std::string line{}; std::getline(input, line, '\n') and line != ""; ) {
        sum += std::atoi(line.c_str());
    }
    return sum;
}

// find the greatest sum of calories
int part1(const char* filename) {
    auto input = std::ifstream{filename};
    if (not input) { return 0; }

    int max = 0;
    for (int sum = sum_next(input); sum != 0; sum = sum_next(input)) {
        if (sum > max) { max = sum; }
    }
    input.close();
    return max;
}

// find top 3 values and return their sum
int part2(const char* filename) {
    auto input = std::ifstream{filename};
    if (not input) { return 0; }

    std::vector<int> totals{250};
    for (int sum = sum_next(input); sum != 0; sum = sum_next(input)) {
        totals.emplace_back(sum);
    }
    input.close();

    std::sort(totals.begin(), totals.end(), [](const auto& lhs, const auto& rhs) { return lhs > rhs; });
    const auto top_3 = std::span{totals.begin(), 3};
    totals.clear();
    
    int sum = 0;
    for (const auto& n : top_3) {
        sum += n;
    }
    return sum;
}

/**
 * https://adventofcode.com/2022/day/1
 * 
 * Usage: ./day01 [<part=1> <input-file='./input.txt'>]
 *        make run [args="<part> <input-file>"]
*/
int main(const int argc, const char** argv) {
    using namespace std::string_literals;
    const auto fn = (argc <= 1) 
        ? &part1 
        : ("1"s == argv[1]) ? &part1 : &part2;
    fmt::print("{}\n", fn(argc <= 2 ? "./input.txt" : argv[2]));
}
