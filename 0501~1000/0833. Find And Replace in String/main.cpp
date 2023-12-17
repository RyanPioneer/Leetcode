/**
 * Source: jpeg.ly/lwQ6k
 * Date: 2023/12/16
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 86.52% of C++ online submissions
 * Memory Usage: 14.82 MB, less than 5.87% of C++ online submissions
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
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<vector<int>> idx;
        for (int i = 0; i < indices.size(); i++) idx.push_back({indices[i], i});
        sort(begin(idx), end(idx));
        int added_len = 0;
        for (int i = 0; i < idx.size(); i++) {
            int start = idx[i][0] + added_len, id = idx[i][1];
            bool check = true;
            for (int j = 0; j < sources[id].length(); j++) {
                if (s[start + j] != sources[id][j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                s = s.substr(0, start) + targets[id] + s.substr(start + sources[id].length());
                added_len += targets[id].length() - sources[id].length();
            }
        }
        return s;
    }
};