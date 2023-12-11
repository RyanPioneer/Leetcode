/**
 * Source: jpeg.ly/QwINZ
 * Date: 2023/12/9
 * Skill:
 * Ref:
 * Runtime: 76 ms, faster than 81.29% of C++ online submissions
 * Memory Usage: 39.41 MB, less than 74.84% of C++ online submissions
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


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> content2path;
        for (auto &p: paths) {
            string path;
            int idx = 0, len = path.length();
            while (p[idx] != ' ') idx++;
            path = p.substr(0, idx);
            while (idx < len) {
                int start = ++idx;
                while (p[idx] != '(') idx++;
                string p2 = p.substr(start, idx - start);
                idx++;
                int s = idx;
                while (p[idx] != ')') idx++;
                string content = p.substr(s, idx - s);
                idx++;
                content2path[content].push_back(path + "/" + p2);
            }
        }
        for (auto m: content2path) {
            res.push_back(m.second);
        }
        return res;
    }
};