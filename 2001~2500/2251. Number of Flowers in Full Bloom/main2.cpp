/**
 * Source: ibit.ly/2WxOY
 * Date: 2023/10/13
 * Skill:
 * Runtime: 303 ms, faster than 18.31% of C++ online submissions
 * Memory Usage: 105.06 MB, less than 6.10% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        unordered_map<int, vector<int>> time2idx;
        vector<int> res(people.size(), 0), diff_arr(people.size(), 0);
        for (int i = 0; i < people.size(); i++)
            time2idx[people[i]].push_back(i);
        people.erase(std::unique(people.begin(), people.end()), people.end());
        sort(people.begin(), people.end());
        for (auto i: flowers) {
            auto it = lower_bound(begin(people), end(people), i[0]);
            if (it != end(people)) {
                diff_arr[it - begin(people)]++;
                it = upper_bound(begin(people), end(people), i[1]);
                if (it != end(people))
                    diff_arr[it - begin(people)]--;
            }
        }
        int cur_num = 0;
        for (int i = 0; i < people.size(); i++) {
            cur_num += diff_arr[i];
            for (auto j: time2idx[people[i]])
                res[j] = cur_num;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    vector<int> res = s.fullBloomFlowers(arr, nums);
}