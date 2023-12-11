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
#define ll long long
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 1e5+1;


class Solution {
//    map<PII, ll> div;
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> right;
        for (int i = 0; i < nums.size(); i++) {
            right[nums[i]] = i;
        }
        int num = 0, cur_right = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_right = max(cur_right, right[nums[i]]);
            if (cur_right == i) num++;
        }
        vector<int> dp(num, 0);
        dp[0] = 1;
        for (int i = 1; i < num; i++) {
            dp[i] = 2 * dp[i - 1] % mod;
        }
        return dp[num - 1];
    }
//    ll divide(int num, int group) {
//        if (group > num) return 0;
//        if (num == group || group == 1) return 1;
//        if (div[{num, group}] != 0) return div[{num, group}];
//        ll cnt = 0;
//        for (int i = 0; i < num - group + 1; i++) {
//            cnt = (cnt + divide(num - i - 1, group - 1)) % mod;
//        }
//        div[{num, group}] = cnt;
//        return cnt;
//    }
};