/**
 * Source: tinyurl.com/ywzn8ouq
 * Date: 2023/10/28
 * Skill:
 * Runtime: 371 ms, faster than 95.92% of C++ online submissions
 * Memory Usage: 146.89 MB, less than 50.66% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool feasible[3] = {false, false, false};
        for (auto &t: triplets) {
            for (int i = 0; i < 3; i++) {
                if (t[i] == target[i] && t[(i + 1) % 3] <= target[(i + 1) % 3] &&
                    t[(i + 2) % 3] <= target[(i + 2) % 3]) {
                    feasible[i] = true;
                }
            }
        }
        return feasible[0] && feasible[1] && feasible[2];
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
}