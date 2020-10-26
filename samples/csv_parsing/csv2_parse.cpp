#include <chrono>
#include "csv2.hpp"
#include <benchmark/benchmark.hpp>
#include <iostream>
using namespace csv2;

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cout << "Usage: ./main <csv_file>\n";
    return EXIT_FAILURE;
  }

  benchmark("Benchmark #1 csv2 {" + std::string{argv[1]} + "}", [&argv] {
    Reader<delimiter<','>, quote_character<'"'>, first_row_is_header<false>> csv;
    if (csv.mmap(argv[1])) {
      size_t rows{0}, cells{0};
      for (const auto row : csv) {
        rows += 1;
        for (const auto cell : row) {
          cells += 1;
        }
      }
    } else {
      std::cout << "error: Failed to open " << argv[1] << std::endl;
    }
  });
}