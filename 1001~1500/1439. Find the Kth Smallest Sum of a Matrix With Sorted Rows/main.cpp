/**
 * Source: t.ly/oHyt8
 * Date: 2023/11/9
 * Skill:
 * Runtime: 133 ms, faster than 33.08% of C++ online submissions
 * Memory Usage: 56.96 MB, less than 13.08% of C++ online submissions
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

const int MX = 1e5 + 1;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<vector<int>> cnt;
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        set<vector<int>> visited;
        int num = 0, total = 0, m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) total += mat[i][0];
        vector<int> pos(m, 0);
        cnt.push_back(pos);
        visited.insert(pos);
        pq.push({total, num++});
        for (int i = 0; i < k; i++) {
            auto [sum, idx] = pq.top();
            pq.pop();
            if (i == k - 1) return sum;
            for (int j = 0; j < m; j++) {
                if (cnt[idx][j] == n - 1) continue;
                vector<int> p = cnt[idx];
                p[j]++;
                if (visited.find(p) != visited.end()) continue;
                visited.insert(p);
                cnt.push_back(p);
                pq.push({sum + mat[j][p[j]] - mat[j][p[j] - 1], num++});
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}