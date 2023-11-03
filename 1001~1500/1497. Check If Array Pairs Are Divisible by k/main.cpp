/**
 * Source: t.ly/odHa9
 * Date: 2023/11/3
 * Skill:
 * Runtime: 79 ms, faster than 97.00% of C++ online submissions
 * Memory Usage: 60.97 MB, less than 99.05% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e5+1;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt[MX] = {0};
        for (auto i: arr) cnt[(i + k * 10000) % k]++;
        if (cnt[0] % 2 == 1) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}