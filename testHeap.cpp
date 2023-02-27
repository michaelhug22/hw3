#include <iostream>
#include <cassert>
#include "heap.h"

using namespace std;

void test_heap() {
    Heap<int> h(2);
    assert(h.empty() == true);
    assert(h.size() == 0);

    h.push(5);
    h.push(7);
    h.push(3);
    h.push(9);
    h.push(1);

    assert(h.empty() == false);
    assert(h.size() == 5);
    assert(h.top() == 1);

    h.pop();
    assert(h.top() == 3);
    h.pop();
    assert(h.top() == 5);

    h.push(0);
    assert(h.top() == 0);

    h.pop();
    assert(h.top() == 5);

    h.pop();
    assert(h.top() == 7);

    h.pop();
    assert(h.top() == 9);

    h.pop();
    assert(h.empty() == true);
    assert(h.size() == 0);

    cout << "All tests passed!" << endl;
}

int main() {
    test_heap();
    return 0;
}