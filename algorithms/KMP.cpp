//
// Created by wdiantao on 2021/12/22.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Description: Implementation of KMP algorithm.
 * substr(): returns all start positions (eg. pi) that
 * s[pi, ...] matches target.
 */

vector<int> gen_next(const string &s) {
    int n = (int) s.size();
    vector<int> next(n, -1);
    for (int i = 1, p = -1; i < n; ++i) {
        while (p >= 0 && s[p + 1] != s[i]) {
            p = next[p];
        }
        if (s[p + 1] == s[i]) {
            ++p;
        }
        next[i] = p;
    }
    return next;
}

vector<int> substr(const string &s, const string &target) {
    int n = (int) s.size(), m = (int) target.size();
    vector<int> pos, next = gen_next(target);
    for (int i = 0, p = -1; i < n; ++i) {
        while (p >= 0 && target[p + 1] != s[i]) {
            p = next[p];
        }
        if (target[p + 1] == s[i]) {
            ++p;
        }
        if (p == m - 1) {
            pos.emplace_back(i - m + 1);
            p = next[p];
        }
    }
    return pos;
}
