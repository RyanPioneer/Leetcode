/**
 * Source: tinyurl.com/28c7admw
 * Date: 2024/4/27
 * Skill: 先固定中間，這樣找兩側的座標便只需要O(N)。如果先固定左邊或右邊，找另兩個座標需要O(N ^ 2)。
 * Ref:
 * Runtime: 112 ms, faster than 62.96% of C++ online submissions
 * Memory Usage: 17.02 MB, less than 40.74% of C++ online submissions
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


const int MX = 2e3+10;


class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size(), presum[MX] = {0};

        for (int i = 1; i <= n; i++) presum[i] = presum[i - 1] + nums[i - 1];
        for (int mid = 3; mid < n - 3; mid++) {
            unordered_set<int> leftSet;
            for (int i = 1; i + 1 < mid; i++) {
                int first = presum[i], second = presum[mid] - presum[i + 1];
                if (first == second) {
                    leftSet.insert(first);
                }
            }
            for (int k = mid + 2; k + 1 < n; k++) {
                int first = presum[k] - presum[mid + 1], second = presum[n] - presum[k + 1];
                if (first == second && leftSet.find(first) != leftSet.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};