//
// Created by wdiantao on 2022/04/05.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Description: Implementation of Z (extern-KMP) algorithm.
 * z_function(): returns array z, which z[i] represents the
 * length of the longest common prefix (LCP) of s and s[i, n-1].
 */

vector<int> z_function(const string &s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
