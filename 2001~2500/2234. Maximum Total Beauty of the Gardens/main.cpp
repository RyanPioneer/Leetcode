/**
 * Source: tinyurl.com/ypsm3u69
 * Date: 2023/10/21
 * Skill:
 * Runtime: 179 ms, faster than 72.12% of C++ online submissions
 * Memory Usage: 84.78 MB, less than 68.27% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        int sz = flowers.size(), tail = flowers.size();
        if (flowers[0] >= target)
            return (ll)full * sz;
        vector<ll> presum(flowers.size(), 0);
        ll res = 0, cur_num = 0;
        for (int i = 1; i < sz; i++) {
            if (flowers[i] >= target)
                presum[i] = LLONG_MAX;
            else
                presum[i] = presum[i - 1] + (flowers[i] - flowers[i - 1]) * i;
        }
        while (flowers[tail - 1] >= target)
            tail--;
        while (tail >= 0 && newFlowers - cur_num >= 0) {
            ll budget = newFlowers - cur_num, val = (ll)full * (sz - tail);
            if (tail == 0) {
                res = max(res, val);
                break;
            }
            int idx = upper_bound(presum.begin(), presum.end(), budget) - begin(presum);
            idx = min(idx, tail);
            budget -= presum[idx - 1];
            if (budget >= ((ll)target - flowers[idx - 1] - 1) * idx)
                val += (ll)(target - 1) * partial;
            else
                val += ((ll)flowers[idx - 1] + budget / idx) * partial;
            res = max(res, val);
            if (tail > 0)
                cur_num += target - flowers[tail - 1];
            tail--;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{16015,83595,20480,15561,28935,77358,67631,89017,28075,8236,84626,43499,36525,33996,77506,86356,63494,86522,67946,26589,39640,5125,12582,17579,62836,44184,55188,12118,7452,75275,20641,60301,38188,5773,59560,97845,44972,56966,11023,32923,61037,66458,49831,45438,88440,64707,3914,98959,48990,11665,20125,45743,53724,84109,81790,13114,81187,76080,45212,5017,13402,11580,66844,68715,8932,29354,15529,98875,64256,28013,55294,89135};
    ll res = s.maximumBeauty(nums, 3281526, 100000,86095,12739);
    cout << res << endl;
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}