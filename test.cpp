#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include "binaryheap.hpp"

int main() {
    std::vector<int> numbers;
    BinaryHeap<int, int> heap;
    for (int i = 0; i < 100000; i++) {
        int n = rand();
        heap.insert(n, n);
        numbers.push_back(n);
    }
    std::sort(numbers.begin(), numbers.end());
    std::vector<int> numbers2;
    while (!heap.empty()) {
        int payload, value;
        heap.top(payload, value);
        heap.pop();
        assert(payload == value);
        numbers2.push_back(value);
    }
    assert(numbers == numbers2);
}
