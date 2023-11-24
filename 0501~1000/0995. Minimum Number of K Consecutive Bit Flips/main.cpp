/**
 * Source: is.gd/fVc70y
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 88 ms, faster than 93.29% of C++ online submissions
 * Memory Usage: 107.12 MB, less than 71.48% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5 + 1;


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int diff[MX] = {0}, res = 0, flip_time = 0, len = SZ(nums);
        for (int i = 0; i <= len - k; i++) {
            flip_time += diff[i];
            if ((nums[i] + flip_time) % 2 == 0) {
                res++;
                flip_time++;
                diff[i + k]--;
            }
        }
        for (int i = len - k + 1; i < len; i++) {
            flip_time += diff[i];
            if ((nums[i] + flip_time) % 2 == 0) {
                return -1;
            }
        }
        return res;
    }
};