/**
 * Source: t.ly/FgxhD
 * Date: 2023/11/6
 * Skill:
 * Runtime: 528 ms, faster than 58.57% of C++ online submissions
 * Memory Usage: 206.35 MB, less than 45.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        set<int> odd, even;
        unordered_set<int> ban;
        for (auto &i: banned) ban.insert(i);
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            if (i == p) continue;
            if (ban.find(i) != ban.end()) continue;
            if (i % 2 == 0) even.insert(i);
            else odd.insert(i);
        }
        res[p] = 0;
        queue<int> q;
        q.push(p);
        int step = 0;
        while (!q.empty()) {
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int pos = q.front();
                q.pop();
                int l = max(0, pos - k + 1);
                int left = 2 * l + k - 1 - pos;
                int r = min(pos, n - k);
                int right = 2 * r + k - 1 - pos;
                set<int> *n = (left % 2 == 0 ? &even : &odd);
                auto iter = n->lower_bound(left);
                while (iter != n->end() && *iter <= right) {
                    res[*iter] = step;
                    q.push(*iter);
                    iter = next(iter);
                    n->erase(prev(iter));
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    vector<int> nums{0, 1};
}