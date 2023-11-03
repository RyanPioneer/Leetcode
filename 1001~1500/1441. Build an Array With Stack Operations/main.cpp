/**
 * Source: t.ly/idS5N
 * Date: 2023/11/3
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.08 MB, less than 75.36% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        const string push = "Push", pop = "Pop";
        const int sz = target.size();
        int idx = 0;
        vector<string> res;
        for (int i = 1; i <= n, idx < sz; i++) {
            res.push_back(push);
            if (i != target[idx]) {
                res.push_back(pop);
            } else {
                idx++;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}