//
// Created by wdiantao on 2022/1/31.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Disjoint-Set data structure.
 * Supporting path compression and merge by rank which represented
 * by the depth of the sub-tree.
 */

class DisjointSet {
public:
    DisjointSet(int _n) : N(_n){
        fa.resize(N);
        rank.resize(N);
        for (int i = 0; i < N; ++i) {
            fa[i] = i;
            rank[i] = 0;
        }
    }
    
    void merge(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x == root_y) {
            return;
        }
        if (rank[root_x] >= rank[root_y]) {
            fa[root_y] = root_x;
        } else {
            fa[root_x] = root_y;
        }
        if (rank[root_x] == rank[root_y]) {
            ++rank[root_x];
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
    vector<int> rank;
};
