/**
 * Source: t.ly/h_38O
 * Date: 2023/11/8
 * Skill:
 * Runtime: 588 ms, faster than 85.57% of C++ online submissions
 * Memory Usage: 178.50 MB, less than 75.26% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

const int MX = 2 * 1e4 + 1;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> res, deg(n, 0);
        int degree[MX] = {0};
        unordered_map<ll, int> edge2num;
        for (auto &e: edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            deg[e[0] - 1]++;
            deg[e[1] - 1]++;
            ll hash = min(e[0], e[1]) * MX + max(e[0], e[1]);
            edge2num[hash]++;
        }
        sort(begin(deg), end(deg));
        for (auto q: queries) {
            int right = n - 1, num = 0;
            for (int i = 0; i < n; i++) {
                if (i >= right) {
                    num += n - i - 1;
                    continue;
                }
                while (right > i && deg[right] + deg[i] > q) right--;
                num += n - right - 1;
            }
            for (auto [edgeIdx, cnt]: edge2num) {
                int n1 = edgeIdx / MX, n2 = edgeIdx % MX;
                if (degree[n1] + degree[n2] <= q) continue;
                if (degree[n1] + degree[n2] - cnt <= q) {
                    num--;
                }
            }
            res.push_back(num);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}