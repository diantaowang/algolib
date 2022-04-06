//
// Created by wdiantao on 2022/04/06.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Description: Implementation of Binary Index Tree (BIT).
 * Supporting single point modification and interval summation.
 */

class BIT {
public:
    BIT() = default;
    BIT(vector<long long> &arr);
    BIT(int n);
    void update(int pos, long long val);
    long long query(int pos);
    long long query(int l, int r);
    void init(vector<long long> &arr);
private:
    inline static int lowbit(int x) {
        return x & (-x);
    }
    vector<long long> sums, nums;
};

void BIT::init(vector<long long> &arr) {
    nums.resize(arr.size(), 0);
    sums.resize(arr.size() + 1, 0);
    int size = (int) sums.size();
    for (int i = 1; i < size; ++i) {
        update(i, arr[i - 1]);
    }
}

BIT::BIT(vector<long long> &arr) {
    init(arr);
}

BIT::BIT(const int n) {
    nums.resize(nums.size(), 0);
    sums.resize(nums.size() + 1, 0);
}

void BIT::update(int pos, long long val) {
    int size = (int) sums.size(), diff = val - nums[pos - 1];
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
