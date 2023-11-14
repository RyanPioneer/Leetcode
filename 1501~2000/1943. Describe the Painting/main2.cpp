/**
 * Source: t.ly/hPWAh
 * Date: 2023/11/14
 * Skill: difference array
 * Runtime: 292 ms, faster than 77.24% of C++ online submissions
 * Memory Usage: 103.80 MB, less than 62.60% of C++ online submissions
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


typedef pair<int, int> pairs;

#define ll long long


class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<ll>> res;
        map<int, ll> diff_array;
        for (auto &i: segments) {
            diff_array[i[0]] += i[2];
            diff_array[i[1]] -= i[2];
        }
        ll cur_color = 0, start = begin(diff_array)->first;
        for (auto &iter: diff_array) {
            if (start != iter.first && cur_color > 0) {
                res.push_back({start, iter.first, cur_color});
            }
            start = iter.first;
            cur_color += iter.second;
        }
        return res;
    }
};


int main() {
    Solution s;
}