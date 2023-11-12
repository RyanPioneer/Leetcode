/**
 * Source: t.ly/gbyAK
 * Date: 2023/11/12
 * Skill:
 * Runtime: 474 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 127.74 MB, less than 50.00% of C++ online submissions
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
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = *max_element(begin(nums), end(nums)), res = 0, mask = 0;
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;
        unordered_map<int, int> seen;
        for (int i = high_bit; i >= 0; i--) {
            mask |= 1 << i;
            seen.clear();
            int new_res = res | (1 << i);
            for (auto &i: nums) {
                int hash = i & mask;
                if (seen[new_res ^ hash] * 2 >= i) {
                    res = new_res;
                    break;
                }
                seen[hash] = i;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}