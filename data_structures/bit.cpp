//
// Created by wdiantao on 2022/1/16.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Binary Index Tree (BIT).
 * Supporting single point modification and interval summation.
 */

class BIT {
public:
    BIT(vector<long long> &arr);
    BIT(const int n);
    void update(int pos, long long val);
    long long quary(int pos);
    long long quary(int l, int r);
private:
    inline int lowbit(int x) {
        return x & (-x);
    }
    int size = 0;
    vector<long long> sums;
};

BIT::BIT(vector<long long> &arr) {
    size = arr.size() + 1;
    sums.resize(size);
    fill(sums.begin(), sums.end(), 0);
    for (int i = 1; i < size; ++i) {
        update(i, arr[i - 1]);
    }
}

BIT::BIT(const int n) {
    size = n + 1;
    sums.resize(size);
    fill(sums.begin(), sums.end(), 0);
}

void BIT::update(int pos, long long val) {
    for (int i = pos; i < size; i += lowbit(i)) {
        sums[i] += val;
    }
}

long long BIT::quary(int pos) {
    long long ret = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        ret += sums[i];
    }
    return ret;
}

long long BIT::quary(int l, int r) {
    return quary(r) - quary(l - 1);
}
