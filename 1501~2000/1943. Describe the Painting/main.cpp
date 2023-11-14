/**
 * Source: t.ly/hPWAh
 * Date: 2023/11/14
 * Skill: difference array
 * Runtime: 295 ms, faster than 72.36% of C++ online submissions
 * Memory Usage: 104.87 MB, less than 39.02% of C++ online submissions
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
        map<int, ll> add, del;
        for (auto &i: segments) {
            add[i[0]] += i[2];
            del[i[1]] += i[2];
        }
        ll cur_color = 0, start = begin(add)->first;
        auto iter2 = begin(del);
        for (auto &iter: add) {
            while (iter2 != end(del) && iter2->first <= iter.first) {
                res.push_back({start, iter2->first, cur_color});
                start = iter2->first;
                cur_color -= iter2->second;
                iter2 = next(iter2);
            }
            if (iter.first != start && cur_color > 0) {
                res.push_back({start, iter.first, cur_color});
            }
            cur_color += iter.second;
            start = iter.first;
        }
        while (iter2 != end(del)) {
            res.push_back({start, iter2->first, cur_color});
            start = iter2->first;
            cur_color -= iter2->second;
            iter2 = next(iter2);
        }
        return res;
    }
};


int main() {
    Solution s;
}