/**
 * Source: jpeg.ly/07S5G
 * Date: 2023/12/23
 * Skill:
 * Ref:
 * Runtime: 916 ms, faster than 20.00% of C++ online submissions
 * Memory Usage: 235.40 MB, less than 18.00% of C++ online submissions
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


class Solution {
    map<int, int> mp;
    multiset<int> intervals;
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = queryIndices.size(), len = s.length();
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j < len && s[i] == s[j]) j++;
            add_interval(i, j - 1);
            i = j - 1;
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            insert_idx(s, idx, c);
            if (idx + 1 < len && s[idx] == s[idx + 1]) merge_right(idx);
            if (idx > 0 && s[idx] == s[idx - 1]) merge_left(idx);
            res.push_back(*intervals.rbegin());
        }
        return res;
    }
    void remove_interval(int start) {
        int end = mp[start];
        intervals.erase(intervals.find(end - start + 1));
        mp.erase(start);
    }
    void add_interval(int start, int end) {
        intervals.insert(end - start + 1);
        mp[start] = end;
    }
    void insert_idx(string &s, int idx, char c) {
        s[idx] = c;
        auto it = prev(mp.upper_bound(idx));
        int left = it->first, right = it->second;
        remove_interval(left);
        add_interval(idx, idx);
        if (left == right) return;
        if (idx != right) add_interval(idx + 1, right);
        if (idx != left) add_interval(left, idx - 1);
    }
    void merge_right(int idx) {
        auto it = next(mp.lower_bound(idx));
        int left = it->first, right = it->second;
        remove_interval(left);
        remove_interval(idx);
        add_interval(idx, right);
    }
    void merge_left(int idx) {
        auto it = mp.lower_bound(idx);
        int left = prev(it)->first, right = it->second;
        remove_interval(left);
        remove_interval(idx);
        add_interval(left, right);
    }
};