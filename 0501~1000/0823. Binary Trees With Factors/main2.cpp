/**
 * Source: tinyurl.com/yrhwrfud
 * Date: 2023/10/26
 * Skill: 將array的值提前取出避免重複呼叫array可大幅減少時間
 * Runtime: 28 ms, faster than 91.73% of C++ online submissions
 * Memory Usage: 9.51 MB, less than 55.12% of C++ online submissions
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
            int cur_num = arr[i];
            ll num = 1;
            int limit = sqrt(cur_num);
            for (int j = i - 1; j >= 0; j--) {
                int nxt = arr[j];
                if (nxt <= limit) {
                    if (nxt * nxt == cur_num) {
                        num = (num + cnt[nxt] * cnt[nxt] % mod) % mod;
                    }
                    break;
                }else if (cur_num % nxt == 0 && cnt.find(cur_num / nxt) != cnt.end()) {
                    num = (num + cnt[nxt] * cnt[cur_num / nxt] * 2 % mod) % mod;
                }
            }
            res = (res + num) % mod;
            cnt[cur_num] = num;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}