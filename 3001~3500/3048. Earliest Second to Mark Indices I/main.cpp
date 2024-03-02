/**
 * Source: is.gd/kw73xK
 * Date: 2024/3/2
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 82.99% of C++ online submissions
 * Memory Usage: 40.43 MB, less than 89.36% of C++ online submissions
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

const int MX = 2002;


class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        int used[MX], diff_arr[MX], num = 0, left = 0, right = m;

        function<bool(int time)> check = [&](int time) {
            fill(used, used + MX, 0);
            fill(diff_arr, diff_arr + MX, 0);
            num = 0;
            for (int i = time - 1; i >= 0; i--) {
                if (used[changeIndices[i] - 1] == 0) {
                    used[changeIndices[i] - 1] = 1;
                    diff_arr[i] += nums[changeIndices[i] - 1] + 1;
                    num++;
                }
            }
            if (num != n) return false;
            int cnt = 0;
            for (int i = 0; i < time; i++) {
                cnt += diff_arr[i];
                if (cnt > i + 1) return false;
            }
            return true;
        };

        while (left < right) {
            int mid = (left + right) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return check(left) ? left : -1;
    }
};