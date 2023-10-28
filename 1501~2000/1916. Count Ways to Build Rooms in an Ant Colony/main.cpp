/**
 * Source: tinyurl.com/yplujpqf
 * Date: 2023/10/28
 * Skill:
 * Runtime: 395 ms, faster than 75.74% of C++ online submissions
 * Memory Usage: 140.48 MB, less than 100.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

const int MX = 1e5+1;

#define ll long long

class Solution {
public:
    ll mod = 1e9+7;
    ll inv(int x) {
        ll s = 1;
        for (; x > 1; x = mod % x) s = s * (mod - mod / x) % mod;
        return s;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        ll dp[MX] = {1};
        vector<int> children[MX];
        int sz = prevRoom.size(), in_degree[MX] = {0}, cnt[MX] = {0};
        ll fac[MX] = {1};
        for (int i = 1; i < sz; i++) {
            fac[i] = fac[i - 1] * i % mod;
            dp[i] = cnt[i] = 1;
            in_degree[prevRoom[i]]++;
            children[prevRoom[i]].push_back(i);
        }
        queue<int> q;
        for (int i = 0; i < sz; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int total = 0;
            for (auto i: children[cur]) {
                total += cnt[i];
                dp[cur] = dp[cur] * dp[i] % mod * inv(fac[cnt[i]]) % mod;
            }
            dp[cur] = dp[cur] * fac[total] % mod;
            cnt[cur] = total + 1;
            if (cur == 0) break;
            in_degree[prevRoom[cur]]--;
            if (in_degree[prevRoom[cur]] == 0) q.push(prevRoom[cur]);
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
    int res = s.waysToBuildRooms(nums);
}