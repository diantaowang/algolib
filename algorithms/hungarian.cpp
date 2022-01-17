//
// Created by wdiantao on 2022/1/16.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Hungarian Algorithm for solving the
 * maximum matching problem. Using an adjacency matrix to represent a
 * graph. The time complexity is O(VE).
 */

class Hungarian {
public:
    Hungarian(vector<vector<int>> &_graph);
    int calc();
private:
    bool match(int s);
    vector<vector<int>> graph;
    vector<int> partner;
    vector<bool> visited;
    int m = 0, n = 0;
};

Hungarian::Hungarian(vector<vector<int>> &_graph) : graph(_graph) {
    int m = graph.size();
    if (m) {
        n = graph[0].size();
    }
    partner.resize(n);
    visited.resize(n);
    fill(partner.begin(), partner.end(), -1);
    fill(visited.begin(), visited.end(), false);
}

bool Hungarian::match(int s) {
    for (int d = 0; d < n; ++d) {
        if (graph[s][d] && !visited[d]) {
            visited[d] = true;
            if (partner[d] == -1 || match(partner[d])) {
                partner[d] = s;
                return true;
            }
        }
    }
    return false;
}

int Hungarian::calc() {
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        fill(visited.begin(), visited.end(), false);
        if (match(i)) {
            ++cnt;
        }
    }
    return cnt;
}
