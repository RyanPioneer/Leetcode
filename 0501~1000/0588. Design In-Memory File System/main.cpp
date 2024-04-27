/**
 * Source: t.ly/RQMa-
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 10 ms, faster than 76.11% of C++ online submissions
 * Memory Usage: 19.80 MB, less than 93.45% of C++ online submissions
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
    unordered_map<string, TrieNode *>next;
    unordered_map<string, string> files;
};

class FileSystem {
    TrieNode *root;
public:
    FileSystem() {
        root = new TrieNode();
    }

    vector<string> ls(string path) {
        TrieNode * node = root;
        vector<string> res;
        int pos = 0, n = path.length();
        while (pos < n) {
            if (path[pos] == '/') pos++;
            else {
                string s;
                while (pos < n && path[pos] != '/') {
                    s.push_back(path[pos++]);
                }
                if (node->next.find(s) != end(node->next)) {
                    node = node->next[s];
                } else {
                    res.push_back(s);
                    return res;
                }
            }
        }
        for (auto &i: node->next) res.push_back(i.first);
        for (auto &i: node->files) res.push_back(i.first);
        sort(begin(res), end(res));
        return res;
    }

    void mkdir(string path) {
        TrieNode * node = root;
        int pos = 0, n = path.length();
        while (pos < n) {
            if (path[pos] == '/') pos++;
            else {
                string s;
                while (pos < n && path[pos] != '/') {
                    s.push_back(path[pos++]);
                }
                if (node->next.find(s) == end(node->next)) {
                    node->next[s] = new TrieNode();
                }
                node = node->next[s];
            }
        }
    }

    void addContentToFile(string filePath, string content) {
        TrieNode * node = root;
        int pos = 0, n = filePath.length();
        while (pos < n) {
            if (filePath[pos] == '/') pos++;
            else {
                string s;
                while (pos < n && filePath[pos] != '/') {
                    s.push_back(filePath[pos++]);
                }
                if (pos < n) {
                    if (node->next.find(s) == end(node->next)) {
                        node->next[s] = new TrieNode();
                    }
                    node = node->next[s];
                } else {
                    if (node->files.find(s) == end(node->files)) {
                        node->files[s] = content;
                    } else {
                        node->files[s] += content;
                    }
                }

            }
        }
    }

    string readContentFromFile(string filePath) {
        TrieNode * node = root;
        int pos = 0, n = filePath.length();
        while (pos < n) {
            if (filePath[pos] == '/') pos++;
            else {
                string s;
                while (pos < n && filePath[pos] != '/') {
                    s.push_back(filePath[pos++]);
                }
                if (pos < n) {
                    node = node->next[s];
                } else {
                    return node->files[s];
                }
            }
        }
        return "";
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */