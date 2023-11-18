/**
 * Source: twtr.to/sGPvH
 * Date: 2023/11/18
 * Skill:
 * Runtime: 122 ms, faster than 40.48% of C++ online submissions
 * Memory Usage: 123.93 MB, less than 37.02% of C++ online submissions
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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int total = accumulate(begin(rolls), end(rolls), 0), m = rolls.size();
        int target = mean * (m + n) - total;
        if (target < n || target > n * 6) return res;
        for (int i = n - 1; i >= 0; i--) {
            int num = (target - i <= 6 ? target - i : 6);
            res.push_back(num);
            target -= num;
        }
        return res;
    }
};