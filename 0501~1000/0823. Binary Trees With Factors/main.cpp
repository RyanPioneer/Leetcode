/**
 * Source: tinyurl.com/yrhwrfud
 * Date: 2023/10/26
 * Skill:
 * Runtime: 47 ms, faster than 63.39% of C++ online submissions
 * Memory Usage: 9.39 MB, less than 70.87% of C++ online submissions
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

#define ll long

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll res = 0, mod = 1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, ll> cnt;
        for (int i = 0; i < arr.size(); i++) {
            ll num = 1;
            int limit = sqrt(arr[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] <= limit) {
                    if (arr[j] * arr[j] == arr[i]) {
                        num = (num + cnt[arr[j]] * cnt[arr[j]] % mod) % mod;
                    }
                    break;
                }else if (arr[i] % arr[j] == 0 && cnt.find(arr[i] / arr[j]) != cnt.end()) {
                    num = (num + cnt[arr[j]] * cnt[arr[i] / arr[j]] * 2 % mod) % mod;
                }
            }
            res = (res + num) % mod;
            cnt[arr[i]] = num;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}