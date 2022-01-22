//
// Created by wdiantao on 2022/1/21.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Binary Index Tree (BIT).
 * Supporting interval modification and interval summation.
 */

class BIT2 {
public:
    BIT2(vector<long long> &arr);
    BIT2(const int n);
    void update(int pos, long long val);
    void update_interval(int l, int r, long long val);
    long long query(int pos);
    long long query_interval(int l, int r);
private:
    inline int lowbit(int x) {
        return x & (-x);
    }
    int size;
    vector<long long> sums;
    vector<long long> ntimes_sums;
};

BIT2::BIT2(vector<long long> &arr) {
    size = arr.size() + 1;
    sums.resize(size + 1);
    ntimes_sums.resize(size + 1);
    for (int i = 1; i < size; ++i) {
        update_interval(i, i, arr[i - 1]);
    }
}

BIT2::BIT2(const int n) {
    size = n + 1;
    sums.resize(size + 1);
    ntimes_sums.resize(size + 1);
    fill(sums.begin(), sums.end(), 0);
    fill(ntimes_sums.begin(), ntimes_sums.end(), 0);
}

void BIT2::update(int pos, long long val) {
    long long delta = (pos - 1) * val;
    for (int i = pos; i < size; i += lowbit(i)) {
        sums[i] += val;
        ntimes_sums[i] += delta;
    }
}

void BIT2::update_interval(int l, int r, long long val) {
    update(l, val);
    update(r + 1, -val);
}

long long BIT2::query(int pos) {
    long long ret = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        ret += pos * sums[i] - ntimes_sums[i];
    }
    return ret;
}

long long BIT2::query_interval(int l, int r) {
    return query(r) - query(l - 1);
}
