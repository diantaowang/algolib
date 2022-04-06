//
// Created by wdiantao on 2021/12/22.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of topological sort. The input
 * graph is represented by an adjacency matrix. If there is
 * no cycle in the graph, TopologicalSort::topological_sort()
 * returns a result, else returns an empty array.
 */

class TopologicalSort {
public:
    TopologicalSort(vector<vector<int>> &_graph);
    vector<int> topological_sort();
private:
    bool dfs(int s);
    vector<vector<int>> &graph;
    vector<int> color;
    vector<int> ret;
};

TopologicalSort::TopologicalSort(vector<vector<int>> &_graph) : graph(_graph) {
    int n = graph.size();
    color.resize(n);
    fill(color.begin(), color.end(), 0);
}

bool TopologicalSort::dfs(int s) {
    color[s] = 1;
    for (const auto &d : graph[s]) {
        if (color[d] == 1) {
            return false;
        } else if (color[d] == 0 && dfs(d) == false) {
            return false;
        }
    }
    color[s] = 2;
    ret.emplace_back(s);
    return true;
}

vector<int> TopologicalSort::topological_sort() {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0 && dfs(i) == false) {
            return {};
        }
    }
    return ret;
}