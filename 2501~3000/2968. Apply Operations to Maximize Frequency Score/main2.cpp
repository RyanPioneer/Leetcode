/**
 * Source: jpeg.ly/RdGml
 * Date: 2023/12/18
 * Skill:
 * Ref:
 * Runtime: 198 ms, faster than 55.56% of C++ online submissions
 * Memory Usage: 86.36 MB, less than 44.44% of C++ online submissions
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
#define ll long long
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums), end(nums));
        int sz = SZ(nums);
        ll presum[MX] = {0};
        for (int i = 0; i < nums.size(); i++) presum[i + 1] = presum[i] + nums[i];
        auto check = [&](int len) {
            int back = len - len / 2 - 1;
            for (ll i = len / 2; i + back < sz; i++) {
                int start = i - len / 2;
                int end = i + back;
                ll diff = (i - start) * nums[i] - (presum[i] - presum[start]) +
                          (presum[end + 1] - presum[i + 1]) - (end - i) * nums[i];
                if (diff <= k) return true;
            }
            return false;
        };
        int lo = 1, hi = sz;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};