#pragma once
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <iomanip>

void insertion(std::vector<int>& a, int left, int right) {
    for (int i = left + 1; i < right; ++i) {
        int value = a[i];
        int j = i - 1;
        while (j >= left && a[j] > value) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = value;
    }
}

void heapify(int a[], int n, int i) {
    int largest = i;
    const int left = 2 * i + 1;
    const int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void heapSort(int a[], int n) {
    if (n <= 1) {
        return;
    }
    buildMaxHeap(a, n);
    for (int i = n - 1; i >= 0; i--) {
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int partition(std::vector<int>& a, int left, int right) {
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

void quickSort(std::vector<int>&a, int left, int right, int depth) {
    if (right - left <= 1) {
        return;
    }
    if (right - left < 16) {
        insertion(a, left, right);
        return;
    }
    if (depth <= 0) {
        heapSort(a.data() + left, right - left);
        return;
    }
    int pi = partition(a, left, right);
    quickSort(a, left, pi, depth - 1);
    quickSort(a, pi + 1, right, depth - 1);
}

void introSort(std::vector<int>& a) {
    if (a.size() <= 1) return;
    int depth = 2 * static_cast<int>(std::log2(a.size()));
    quickSort(a, 0, a.size(), depth);
}
