/**
 * Source: is.gd/d1HwPH
 * Date: 2024/3/2
 * Skill:
 * Ref:
 * Runtime: 49 ms, faster than 41.58% of C++ online submissions
 * Memory Usage: 45.14 MB, less than 31.60% of C++ online submissions
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
typedef pair<int, int> PII;

const int MX = 5002;


class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices2) {
        int n = nums.size(), m = changeIndices2.size();
        for (auto &i: changeIndices2) i--;
        int left = 0, right = m - 1, used[MX];
        multiset<int> cand;
        ll total = accumulate(begin(nums), end(nums), 0ll), num;

        function<bool(int time)> check = [&](int time) {
            vector<int> changeIndices = changeIndices2;
            cand.clear();
            fill(used, used + MX, -1);
            for (int i = 0; i <= time; i++) {
                if (used[changeIndices[i]] == -1 && nums[changeIndices[i]] > 0) {
                    used[changeIndices[i]] = i;
                }
            }
            num = 0;
            for (int i = time; i >= 0; i--) {
                if (used[changeIndices[i]] == i) {
                    int slot = time - i - cand.size();
                    cand.insert(nums[changeIndices[i]]);
                    if (slot < cand.size()) {
                        cand.erase(begin(cand));
                    }
                }
            }
            num = time + 1 - cand.size();
            for (auto &i: cand) num += i;
            return num >= total + n;
        };

        while (left < right) {
            int mid = (left + right) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return check(left) ? left + 1 : -1;
    }
};