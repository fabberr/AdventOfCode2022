#include <fstream>
#include <sstream>
#include <string_view>
#include <map>
#include <utility>

#include "fmt/format.h"
#include "fmt/ranges.h"

std::map<char, int> my_shape_score = {
    { 'X',  1 }, // ROCK
    { 'Y',  2 }, // PAPER
    { 'Z',  3 }, // SCISSORS
};

/**
 * ROCK     = A or X
 * PAPER    = B or Y
 * SCISSORS = C or Z
*/
std::map<std::string, int> outcome_score = {
    { "A X", 3 }, // ROCK, ROCK     = DRAW
    { "A Y", 6 }, // ROCK, PAPER    = WIN
    { "A Z", 0 }, // ROCK, SCISSORS = LOSS

    { "B X", 0 }, // PAPER, ROCK     = LOSS
    { "B Y", 3 }, // PAPER, PAPER    = DRAW
    { "B Z", 6 }, // PAPER, SCISSORS = WIN

    { "C X", 6 }, // SCISSORS, ROCK     = WIN
    { "C Y", 0 }, // SCISSORS, PAPER    = LOSS
    { "C Z", 3 }, // SCISSORS, SCISSORS = DRAW
};

int compute_score(const std::string& moves) {
    return my_shape_score[moves.back()] + outcome_score[moves];
}

/**
 * X = lose
 * Y = draw
 * Z = win
*/
std::map<std::string, std::string> decrypt = {
    { "A X", "A Z" }, // ROCK, LOSE
    { "A Y", "A X" }, // ROCK, DRAW 
    { "A Z", "A Y" }, // ROCK, WIN 

    { "B X", "B X" }, // PAPER, LOSE
    { "B Y", "B Y" }, // PAPER, DRAW
    { "B Z", "B Z" }, // PAPER, WIN

    { "C X", "C Y" }, // SCISSORS, LOSE
    { "C Y", "C Z" }, // SCISSORS, DRAW
    { "C Z", "C X" }, // SCISSORS, WIN
};

/**
 * https://adventofcode.com/2022/day/2
 * 
 * Usage: ./day02 [input-file]
*/
int main(const int argc, const char** argv) {
    const auto filename = argc <= 1 ? "./input.txt" : argv[1];
    std::ifstream input{filename};

    int total_score = 0;
    for (std::string moves; getline(input, moves); ) {
        // total_score += compute_score(moves); // part 1 solution
        total_score += compute_score(decrypt[moves]); // part 2 solution
    }
    fmt::print("{}\n", total_score);
}
