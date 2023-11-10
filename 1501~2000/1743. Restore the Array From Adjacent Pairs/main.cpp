/**
 * Source: t.ly/poCiS
 * Date: 2023/11/10
 * Skill:
 * Runtime: 316 ms, faster than 89.09% of C++ online submissions
 * Memory Usage: 106.47 MB, less than 81.21% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
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
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj_list;
        for (auto &i: adjacentPairs) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        int cur, prev;
        for (auto it: adj_list) {
            if (it.second.size() == 1) {
                cur = it.first;
                break;
            }
        }
        vector<int> res;
        while (true) {
            prev = res.size() == 0 ? cur : res.back();
            res.push_back(cur);
            for (auto i: adj_list[cur]) {
                if (i != prev) {
                    cur = i;
                    break;
                }
            }
            if (cur == res.back()) break;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}