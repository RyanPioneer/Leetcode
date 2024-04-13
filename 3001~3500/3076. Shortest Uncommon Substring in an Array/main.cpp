/**
 * Source: is.gd/ToeTuB
 * Date: 2024/3/24
 * Skill:
 * Ref:
 * Runtime: 212 ms, faster than 42.86% of C++ online submissions
 * Memory Usage: 108.83 MB, less than 28.57% of C++ online submissions
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

const int MX = 110;


class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_set<string> cand[MX];
        vector<string> res(n, "");
        for (int i = 0; i < n; i++) {
            for (int j = i; j < arr[i].length(); j++) {
                for
            }
        }
        function<void(int idx)> helper = [&](int idx) {

        };

        for (int i = 0; i < n; i++) helper(i);
        return res;
    }
};