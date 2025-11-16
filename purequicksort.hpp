#pragma once
#include <vector>
#include <algorithm>

int partitionPure(std::vector<int>& a, int left, int right) {
    int pivot = a[right - 1];
    int i = left;
    for (int j = left; j < right - 1; ++j) {
        if (a[j] <= pivot) {
            std::swap(a[i], a[j]);
            ++i;
        }
    }
    std::swap(a[i], a[right - 1]);
    return i;
}

void quickSortPure(std::vector<int>& a, int left, int right) {
    if (right - left <= 1)
        return;

    int pi = partitionPure(a, left, right);
    quickSortPure(a, left, pi);
    quickSortPure(a, pi + 1, right);
}
