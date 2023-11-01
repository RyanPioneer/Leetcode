/**
 * Source: t.ly/6nuxi
 * Date: 2023/11/1
 * Skill: set中的數為當前右端點的數二進制中逐漸減少1，因此至多32個元素。
 * Runtime: 620 ms, faster than 53.34% of C++ online submissions
 * Memory Usage: 168.24 MB, less than 55.83% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> nums, nxt;
        int res = INT32_MAX;
        for (auto &i: arr) {
            nxt.clear();
            res = min(res, abs(i - target));
            nxt.insert(i);
            for (auto j: nums) {
                j &= i;
                res = min(res, abs(j - target));
                nxt.insert(j);
            }
            nums = nxt;
        }
        return res;
    }
};


int main() {
    Solution s;
}