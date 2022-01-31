//
// Created by wdiantao on 2022/1/31.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Trie Tree.
 * Supporting empty string operations (insert, delect).
 */

struct Trie {
    Trie *next[26];
    bool end;
    int cnt;
    Trie() : end(false), cnt(0) {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }      
    }
};

void insert(Trie *head, const string &word) {
    auto ptr = head;
    for (const auto &c : word) {
        int idx = c - 'a';
        if (ptr->next[idx] == nullptr) {
            ptr->next[idx] = new Trie();
            ++(ptr->cnt);
        }
        ptr = ptr->next[idx];
    }
    ptr->end = true;
}

bool search(Trie *head, const string &word) {
    auto ptr = head;
    for (const auto &c : word) {
        int idx = c - 'a';
        if (ptr->next[idx] == nullptr) {
            return false;
        }
        ptr = ptr->next[idx];
    }
    return ptr->end;
}

bool startWith(Trie *head, const string &prefix) {
    auto ptr = head;
    for (const auto &c : prefix) {
        int idx = c - 'a';
        if (ptr->next[idx] == nullptr) {
            return false;
        }
        ptr = ptr->next[idx];
    }
    return true;
}

Trie* dfs(Trie *root, Trie *head, const string &word, int n) {
    if (word.size() == 0 || n == word.size() && head->cnt) {
        head->end = false;
        return head;
    } else if (n == word.size()) {
        delete head;
        return nullptr;
    }
    int idx = word[n] - 'a';
    if (head->next[idx] == nullptr) {
        return head;
    }
    head->next[idx] = dfs(root, head->next[idx], word, n + 1);
    if (head->next[idx] == nullptr) {
        --(head->cnt);
    }
    if (head->cnt == 0 && !head->end && head != root) {
        delete head;
        return nullptr;
    }
    return head;
}

void delect(Trie *head, const string &word) {
    dfs(head, head, word, 0);     
}

/*
int main() {
    Trie *trie = new Trie();
    insert(trie, "abc");
    insert(trie, "abcd");
    delect(trie, "abs");
    cout << search(trie, "abc") << endl;
    cout << search(trie, "abcd") << endl;
    cout << search(trie, "abs") << endl;
    delect(trie, "abc");
    delect(trie, "abcd");
    cout << search(trie, "abc") << endl;
    cout << search(trie, "abcd") << endl;
    cout << search(trie, "abs") << endl;
    return 0;
}
*/
