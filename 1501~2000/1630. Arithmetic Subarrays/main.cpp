/**
 * Source: is.gd/eJJakz
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 39 ms, faster than 88.31% of C++ online submissions
 * Memory Usage: 21.26 MB, less than 97.08% of C++ online submissions
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


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = SZ(l);
        vector<bool> res;
        vector<int> vec;
        for (int i = 0; i < m; i++) {
            int left = l[i], right = r[i];
            vec.clear();
            for (int j = left; j <= right; j++) vec.push_back(nums[j]);
            sort(begin(vec), end(vec));
            bool check = true;
            for (int j = 2; j < SZ(vec); j++) {
                if (vec[j] - vec[j - 1] != vec[j - 1] - vec[j - 2]) {
                    check = false;
                    break;
                }
            }
            res.push_back(check);
        }
        return res;
    }
};