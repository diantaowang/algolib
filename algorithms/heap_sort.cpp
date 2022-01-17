//
// Created by wdiantao on 2021/12/31.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of heap sort. HeapSort::sort() returns
 * lexicographical order. HeapSort::sort() returns inverse lexicographical
 * order.
 */

class HeapSort {
public:
    HeapSort(vector<int> &_nums) : nums(_nums) {}
    void sort();
    void rsort();
private:
    inline int left(int val) {
        return (val << 1) + 1;
    }
    inline int right(int val) {
        return (val << 1) + 2;
    }
    void max_heapify(int i, int size);
    void min_heapify(int i, int size);
    void heap_init();
    void rheap_init() ;
    vector<int> &nums;
};

void HeapSort::max_heapify(int i, int size) {
    int l = left(i), r = right(i);
    int maximum = i;
    if (l < size && nums[l] > nums[maximum]) {
        maximum = l;
    }
    if (r < size && nums[r] > nums[maximum]) {
        maximum = r;
    }
    if (maximum != i) {
        swap(nums[i], nums[maximum]);
        max_heapify(maximum, size);
    }
}

void HeapSort::heap_init() {
    int size = nums.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        max_heapify(i, size);
    }
}

void HeapSort::sort() {
    int size = nums.size();
    heap_init();
    while(--size > 0) {
        swap(nums[0], nums[size]);
        max_heapify(0, size);
    }
}

void HeapSort::min_heapify(int i, int size) {
    int l = left(i), r = right(i);
    int minimum = i;
    if (l < size && nums[l] < nums[minimum]) {
        minimum = l;
    }
    if (r < size && nums[r] < nums[minimum]) {
        minimum = r;
    }
    if (minimum != i) {
        swap(nums[i], nums[minimum]);
        max_heapify(minimum, size);
    }
}

void HeapSort::rheap_init() {
    int size = nums.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        min_heapify(i, size);
    }
}

void HeapSort::rsort() {
    int size = nums.size();
    rheap_init();
    while (--size > 0) {
        swap(nums[0], nums[size]);
        min_heapify(0, size);
    }
}