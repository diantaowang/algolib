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
    long long query(int pos);
    long long query(int l, int r);
private:
    inline int lowbit(int x) {
        return x & (-x);
    }
    vector<long long> sums, nums;
};

BIT::BIT(vector<long long> &arr) {
    nums.resize(arr.size(), 0);
    sums.resize(arr.size() + 1, 0);
    int size = sums.size();
    for (int i = 1; i < size; ++i) {
        update(i, nums[i - 1]);
    }
}

BIT::BIT(const int n) {
    nums.resize(n, 0);
    sums.resize(n + 1, 0);
}

void BIT::update(int pos, long long val) {
    int size = sums.size(), diff = val - nums[pos - 1];
    for (int i = pos; i < size; i += lowbit(i)) {
        sums[i] += diff;
    }
    nums[pos - 1] = val;
}

long long BIT::query(int pos) {
    long long ret = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        ret += sums[i];
    }
    return ret;
}

long long BIT::query(int l, int r) {
    return query(r) - query(l - 1);
}

