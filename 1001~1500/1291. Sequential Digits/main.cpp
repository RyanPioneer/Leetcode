/**
 * Source: ibit.ly/OPOec
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.46 MB, less than 30.82% of C++ online submissions
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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        function<void(int)> helper = [&](int num) {
            if (num > high) return;
            if (num >= low) res.push_back(num);
            if (num % 10 < 9) {
                helper(num * 10 + num % 10 + 1);
            }
        };

        for (int i = 1; i < 9; i++) {
            helper(i);
        }
        sort(begin(res), end(res));
        return res;
    }
};