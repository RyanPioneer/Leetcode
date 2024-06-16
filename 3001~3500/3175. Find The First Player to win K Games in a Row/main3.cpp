/**
 * Source: ibit.ly/OxUo2
 * Date: 2024/6/9
 * Skill:
 * Ref:
 * Runtime: 141 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 119.01 MB, less than 60.00% of C++ online submissions
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
    int findWinningPlayer(vector<int>& skills, int k) {
        int left = 0;
        for (int right = 1; right < skills.size(); right++) {
            if (skills[right] > skills[left]) {
                left = right;
                if (k == 1) return left;
            } else if (right - left >= k - (left != 0)){
                return left;
            }
        }
        return left;
    }
};