/**
 * Source: https://rb.gy/6tqrf
 * Date: 2023/9/13
 * Skill:
 * Runtime: 7 ms, faster than 94.53% of C++ online submissions
 * Memory Usage: 10.96 MB, less than 20.19% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        ll res = 0, mod = 1e9+7;
        map<int, ll> cnt;
        for (auto i: arr)
            cnt[i]++;
        for (auto p1 = begin(cnt); p1 != end(cnt); p1 = next(p1)) {
            if (p1->first * 3 > target)
                break;
            else if (p1->first * 3 == target)
                res = (res + p1->second * (p1->second - 1) * (p1->second - 2) / 6);
            else if (cnt.find(target - p1->first * 2) != end(cnt))
                res = (res + p1->second * (p1->second - 1) * cnt[target - p1->first * 2] / 2);
            for (auto p2 = next(p1); p2 != end(cnt); p2 = next(p2)) {
                if (target - p1->first - p2->first < p2->first)
                    break;
                else if (target - p1->first - p2->first == p2->first)
                    res += p1->second * p2->second * (p2->second - 1) / 2;
                else if (cnt.find(target - p1->first - p2->first) != end(cnt))
                    res += p1->second * p2->second * cnt[target - p1->first - p2->first];
            }
        }
        return res % mod;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> arr{1,1,2,2,2,2};
    int res = s.threeSumMulti(arr, 5);
    cout << res << endl;
}