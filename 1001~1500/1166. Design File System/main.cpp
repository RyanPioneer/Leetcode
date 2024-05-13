/**
 * Source: ibit.ly/ThPsV
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 162 ms, faster than 74.60% of C++ online submissions
 * Memory Usage: 65.43 MB, less than 93.65% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;

class TrieNode {
public:
    unordered_map<string, TrieNode *> next;
    int val;

    TrieNode(int v) : val(v){}
};


class FileSystem {
    TrieNode *root;
public:
    FileSystem() {
        root = new TrieNode(0);
    }

    bool createPath(string path, int value) {
        TrieNode *cur = root;
        int pos = 1, len = path.length();
        while (pos < len) {
            int p = pos;
            while (p < len && path[p] != '/') {
                p++;
            }
            string s = path.substr(pos, p - pos);
            if (p < len && cur->next.find(s) == end(cur->next)) {
                return false;
            }
            if (p == len) {
                if (cur->next.find(s) != end(cur->next)) return false;
                cur->next[s] = new TrieNode(value);
                return true;
            }
            pos = ++p;
            cur = cur->next[s];
        }
        return false;
    }

    int get(string path) {
        TrieNode *cur = root;
        int pos = 1, len = path.length();
        while (pos < len) {
            int p = pos;
            while (p < len && path[p] != '/') {
                p++;
            }
            string s = path.substr(pos, p - pos);
            if (cur->next.find(s) == end(cur->next)) {
                return -1;
            }
            pos = ++p;
            cur = cur->next[s];
        }
        return cur->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */