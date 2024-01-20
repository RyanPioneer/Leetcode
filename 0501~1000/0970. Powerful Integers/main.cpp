/**
 * Source: jpeg.ly/GJyrm
 * Date: 2024/1/20
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.70 MB, less than 5.88% of C++ online submissions
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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> nums;
        int num1 = 1;
        while (num1 + 1 <= bound) {
            int num2 = 1;
            while (num1 + num2 <= bound) {
                nums.insert(num1 + num2);
                num2 *= y;
                if (y == 1) break;
            }
            num1 *= x;
            if (x == 1) break;
        }
        vector<int> res;
        for (auto &i: nums) res.push_back(i);
        return res;
    }
};