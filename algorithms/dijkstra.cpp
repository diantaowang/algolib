//
// Created by wdiantao on 2021/2/1.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of dijkstra algorithm using 
 * priority queue. Graph is represented by adjacency list. 
 * The time complexity id O(Elog(E)).
 */

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
	int n = graph.size();
    vector<int> distance(n, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, src});
    distance[src] = 0;
    while (!que.empty()) {
        auto [dist, u] = que.top();
        que.pop();
        if (distance[u] != dist) {
            continue;
        }
        for (auto [v, cost] : graph[u]) {
            if (distance[v] > distance[u] + cost) {
                distance[v] = distance[u] + cost;
                que.push({distance[v], v});
            }
        }
    }
    return distance;
}
