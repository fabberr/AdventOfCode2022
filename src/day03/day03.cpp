#include <filesystem>
namespace fs = std::filesystem;

#include <fstream>
#include <string_view>
#include <array>
#include <utility>
#include <set>
#include <algorithm>

#include "fmt/format.h"
#include "fmt/ranges.h"

/** Types. */
typedef std::string bag_t;
typedef char item_t;

/**
 * Item type priority lookup table.
 * The priority of an item is given by its index in the table + 1.
*/
constexpr std::array priority_lookup = {
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
};

/**
 * Returns the priority of a given item type or -1 if the item was not found.
*/
int priority_of(item_t item) {
    // sequential search
    unsigned int idx = 0;
    while (idx < priority_lookup.size() and item != priority_lookup[idx]) { idx++; }
    return item == priority_lookup[idx] ? ++idx : -1;
}

/**
 * Obtains the set of unique items contained in a single compartment.
*/
std::set<item_t> get_unique_items(const bag_t& compartment) {
    std::set<item_t> unique_items{};
    for (const auto& item : compartment) {
        unique_items.insert(item);
    }
    return unique_items;
}

/**
 * Splits a given item bag into two sets of unique items contained in each bag.
*/
std::pair<std::set<item_t>, std::set<item_t>> split_items(const bag_t& bag) {
    return std::make_pair(
        get_unique_items(bag.substr(0, bag.length() / 2)), 
        get_unique_items(bag.substr(bag.length() / 2))
    );
}

std::set<item_t> intersection_of(std::set<item_t> first, std::set<item_t> second) {
    std::set<item_t> result{};
    std::set_intersection(first.begin(), first.end(), 
                          second.begin(), second.end(), 
                          std::inserter(result, result.begin()));
    return result;
}

/** Solution for part one of the puzzle. */
void part1(std::ifstream& input) {

    unsigned int sum_of_intersecting = 0;
    for (bag_t bag; std::getline(input, bag); ) {
        const auto compartments = split_items(bag);
        const auto intersecting_items = intersection_of(compartments.first, compartments.second);
        sum_of_intersecting += priority_of(*intersecting_items.begin());
    }
    input.close();
    fmt::print("{}\n", sum_of_intersecting);
}

/** Solution for part two of the puzzle. */
void part2(std::ifstream& input) {
    input.close();
}

/**
 * https://adventofcode.com/2022/day/
 * 
 * Usage: ./day03 [input-file]
*/
int main(const int argc, const char** argv) {

    const auto filename = (argc > 1 and fs::is_regular_file(argv[1])) ? argv[1] : "./input.txt";
    if (fs::is_empty(filename)) { return -1; }
    std::ifstream input{filename};

    const auto solve = (not fs::exists("./pt1.answer")) ? &part1 : &part2;
    solve(input);
}
