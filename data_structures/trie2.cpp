//
// Created by wdiantao on 2022/1/31.
//

#include <bits/stdc++.h>

using namespace::std;

/*
 * Description: Implementation of Trie Tree.
 * Supporting empty string operations (insert, delect).
 */

class Trie {
public:
    Trie() : end(false), cnt(0) {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
    
    void insert(string word) {
        auto ptr = this;
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

    bool search(string word) {
        auto ptr = this;
        for (const auto &c : word) {
            int idx = c - 'a';
            if (ptr->next[idx] == nullptr) {
                return false;
            }
            ptr = ptr->next[idx];
        }
        return ptr->end;
    }

    bool startsWith(string prefix) {
        auto ptr = this;
        for (const auto &c : prefix) {
            int idx = c - 'a';
            if (ptr->next[idx] == nullptr) {
                return false;
            }
            ptr = ptr->next[idx];
        }
        return true;
    }

    Trie* dfs(Trie *head, string &word, int n) {
        if (word.empty() || n == word.size() && head->cnt) {
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
        head->next[idx] = dfs(head->next[idx], word, n + 1);
        if (head->next[idx] == nullptr) {
            --(head->cnt);
        }
        if (head->cnt == 0 && !head->end && head != this) {
            delete head;
            return nullptr;
        }
        return head;
    }

    void delect(Trie *head, string word) {
        dfs(head, word, 0);
    }

private:
    Trie *next[26];
    bool end;
    int cnt;
};

/*
int main() {
    Trie *trie = new Trie();
    trie->insert("abc");
    trie->insert("abcd");
    trie->delect(trie, "");
    cout << trie->search("abc") << endl;
    cout << trie->search("abcd") << endl;
    cout << trie->search("abs") << endl;
    // trie->delect(trie, "abc");
    trie->delect(trie, "abcd");
    cout << trie->search("abc") << endl;
    cout << trie->search("abcd") << endl;
    cout << trie->search("abs") << endl;
    return 0;
}
*/
