/**
 * Source: is.gd/L4XQLd
 * Date: 2023/12/13
 * Skill:
 * Ref:
 * Runtime: 18 ms, faster than 97.83% of C++ online submissions
 * Memory Usage: 27.83 MB, less than 70.48% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e4+1;


class TrieNode {
public:
    int num, id;
    TrieNode *next[26];
    TrieNode(int n): id(n), num(0){for (int i = 0; i < 26; i++) next[i] = nullptr;}
    TrieNode(){
        num = 0;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        TrieNode *head = new TrieNode();
        int time[5001] = {0}, id = 0;
        unordered_map<string, int> mp;
        int word_len = words[0].length(), s_len = s.length(), sz = words.size();
        for (int i = 0; i < sz; i++) {
            TrieNode *cur = head;
            for (auto &c: words[i]) {
                if (cur->next[c - 'a'] == nullptr) {
                    cur->next[c - 'a'] = new TrieNode();
                }
                cur = cur->next[c - 'a'];
            }
            cur->num++;
            if (mp.find(words[i]) == end(mp)) {
                mp[words[i]] = id++;
            }
            cur->id = mp[words[i]];
            time[mp[words[i]]]++;
        }

        int group[MX];
        for (int i = 0; i + word_len <= s_len; i++) {
            TrieNode *cur = head;
            for (int j = 0; j < word_len; j++) {
                if (cur->next[s[i + j] - 'a'] == nullptr) {
                    group[i] = -1;
                    break;
                }
                cur = cur->next[s[i + j] - 'a'];
            }
            if (cur->num > 0) {
                group[i] = cur->id;
            }
        }

        vector<int> res;
        int cnt[5001];
        for (int i = 0; i < word_len; i++) {
            int left = i, num = 0;
            fill(cnt, cnt + 5001, 0);
            for (int j = i; j + word_len <= s_len; j += word_len) {
                if (group[j] != -1) {
                    cnt[group[j]]++;
                    num++;
                    while (cnt[group[j]] > time[group[j]]) {
                        while (group[left] == -1) left += word_len;
                        cnt[group[left]]--;
                        num--;
                        left += word_len;
                    }
                    while (group[left] == -1) left += word_len;
                    if ((j - left) / word_len == sz - 1 && num == sz) res.push_back(left);
                }
            }
        }
        return res;
    }
};