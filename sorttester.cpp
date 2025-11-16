#include <iostream>
#include <fstream>
#include <chrono>
#include "arraygenerator.hpp"
#include "introsort.hpp"
#include "purequicksort.hpp"

long timePure(const std::vector<int>& base) {
    std::vector<int> a = base;
    auto t1 = std::chrono::high_resolution_clock::now();
    quickSortPure(a, 0, a.size());
    auto t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long timeIntro(const std::vector<int>& base) {
    std::vector<int> a = base;
    auto t1 = std::chrono::high_resolution_clock::now();
    introSort(a);
    auto t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

int main() {
    ArrayGenerator gen;

    std::vector<int> Ns;
    for (int n = 500; n <= 100000; n += 500)
        Ns.push_back(n);

    std::ofstream pure("results_quick_pure.csv");
    pure << "N,random,reverse,almost\n";

    for (int n : Ns) {
        pure << n << ","
             << timePure(gen.randomArray(n)) << ","
             << timePure(gen.reverseArray(n)) << ","
             << timePure(gen.almostSorted(n)) << "\n";
    }

    std::ofstream intro("results_intro.csv");
    intro << "N,random,reverse,almost\n";

    for (int n : Ns) {
        intro << n << ","
              << timeIntro(gen.randomArray(n)) << ","
              << timeIntro(gen.reverseArray(n)) << ","
              << timeIntro(gen.almostSorted(n)) << "\n";
    }

    return 0;
}
