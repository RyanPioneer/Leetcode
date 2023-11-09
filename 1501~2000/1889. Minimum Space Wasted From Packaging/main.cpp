/**
 * Source: t.ly/6Vx6O
 * Date: 2023/11/7
 * Skill:
 * Runtime: 282 ms, faster than 9.93% of C++ online submissions
 * Memory Usage: 114.36 MB, less than 50.35% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

typedef pair<int, int> pairs;

const int MX = 1e5+1;


class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(begin(packages), end(packages));
        for (auto &b: boxes) {
            sort(b.begin(), b.end(), greater<int>());
        }
        int last_index[MX] = {0}, sz = packages.size();
        ll mod = 1e9+7, res = LLONG_MAX, cost[MX] = {0}, presum[MX] = {0};
        for (int i = 0; i < sz; i++) presum[i + 1] = (presum[i] + packages[i]);
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        for (int i = 0; i < boxes.size(); i++) {
            pq.push({boxes[i].back(), i});
            boxes[i].pop_back();
        }
        for (int i = 0; i < sz; i++) {
            while (!pq.empty() && pq.top().first < packages[i]) {
                auto [cap, idx] = pq.top();
                pq.pop();
                ll num = i - last_index[idx];
                cost[idx] = (cost[idx] + num * cap - (presum[i] - presum[last_index[idx]]));
                last_index[idx] = i;
                while (!boxes[idx].empty() && boxes[idx].back() < packages[i]) boxes[idx].pop_back();
                if (boxes[idx].empty()) {
                    cost[idx] = -1;
                } else {
                    pq.push({boxes[idx].back(), idx});
                    boxes[idx].pop_back();
                }
            }
        }
        while (!pq.empty()) {
            auto [cap, idx] = pq.top();
            pq.pop();
            ll num = sz - last_index[idx];
            cost[idx] = (cost[idx] + num * cap - (presum[sz] - presum[last_index[idx]]));
        }
        for (int i = 0; i < boxes.size(); i++) {
            if (cost[i] == -1) continue;
            res = min(res, cost[i]);
        }
        return res == LLONG_MAX ? -1 : res % mod;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
    ll res = s.minWastedSpace(nums, arr);
}