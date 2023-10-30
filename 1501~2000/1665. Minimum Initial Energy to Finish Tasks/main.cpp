/**
 * Source: ibit.ly/l4ayu
 * Date: 2023/10/30
 * Skill:
 * Runtime: 1860 ms, faster than 10.93% of C++ online submissions
 * Memory Usage: 491.50 MB, less than 5.26% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int lo = 0, hi = INT32_MAX;
        while (lo < hi) {
            int mid = (lo + hi) / 2, budget = (lo + hi) / 2;
            bool finish = true;
            for (auto t: tasks) {
                if (budget < t[1]) {
                    finish = false;
                    break;
                }
                budget -= t[0];
            }
            if (finish) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}