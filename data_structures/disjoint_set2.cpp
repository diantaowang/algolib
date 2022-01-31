//
// Created by wdiantao on 2022/1/31.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Disjoint-Set data structure.
 * Supporting path compression and merge by rank which represented
 * by the size of the sub-tree.
 */

class DisjointSet {
public:
    DisjointSet(int _n) : N(_n){
        fa.resize(N);
        size.resize(N);
        for (int i = 0; i < N; ++i) {
            fa[i] = i;
            size[i] = 1;
        }
    }

    void merge(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x == root_y) {
            return;
        }
        if (size[root_x] >= size[root_y]) {
            fa[root_y] = root_x;
            size[root_x] += size[root_y];
        } else {
            fa[root_x] = root_y;
            size[root_y] += size[root_x];
        }
    }

    int find(int x) {
        if (fa[x] == x) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }

private:
    const int N;
    vector<int> fa;
    vector<int> size;
};