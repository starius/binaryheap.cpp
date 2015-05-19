#include <assert.h>
#include <string>

#include "binaryheap.hpp"

int main() {
    BinaryHeap<std::string, int> heap;
    heap.insert("pos08", 98); // 1
    heap.insert("pos05", 28); // 2
    heap.insert("pos06", 36); // 3
    heap.insert("pos09", 48); // 4
    heap.insert("pos10", 68); // 5
    heap.insert("pos13", 58); // 6
    heap.insert("pos15", 80); // 7
    heap.insert("pos04", 46); // 8
    heap.insert("pos03", 19); // 9
    heap.insert("pos11", 66); // 10
    heap.insert("pos02", 22); // 11
    heap.insert("pos12", 60); // 12
    heap.insert("pos01", 15); // 13
    heap.insert("pos14", 83); // 14
    heap.insert("pos07", 59); // 15
    heap.check();
    //
    heap.update("pos10", 61);
    heap.check();
    //
    std::string payload;
    int value;
    heap.top(payload, value); heap.pop();
    assert(payload == "pos01" && value == 15);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos03" && value == 19);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos02" && value == 22);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos05" && value == 28);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos06" && value == 36);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos04" && value == 46);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos09" && value == 48);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos13" && value == 58);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos07" && value == 59);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos12" && value == 60);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos10" && value == 61);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos11" && value == 66);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos15" && value == 80);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos14" && value == 83);
    heap.top(payload, value); heap.pop();
    assert(payload == "pos08" && value == 98);
    //
    heap.check();
    assert(heap.empty());
    assert(heap.size() == 0);
    return 0;
}
