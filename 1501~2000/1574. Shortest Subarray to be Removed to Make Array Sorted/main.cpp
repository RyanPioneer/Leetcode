/**
 * Source: t.ly/0Aocf
 * Date: 2023/11/2
 * Skill:
 * Runtime: 98 ms, faster than 51.28% of C++ online submissions
 * Memory Usage: 67.20 MB, less than 32.05% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1, sz = arr.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int len = sz - mid;
            int idx = sz - 1;
            for (int i = 0; i < len - 1; i++) {
                if (arr[idx] < arr[idx - 1]) break;
                idx--;
            }
            if (idx == sz - len) {
                hi = mid;
                continue;
            }
            bool stop = false;
            for (int i = 1; i < len - (sz - idx); i++) {
                if (arr[i] < arr[i - 1]) {
                    lo = mid + 1;
                    stop = true;
                    break;
                }
            }
            if (stop) continue;
            if (arr[len - (sz - idx) - 1] <= arr[idx]) {
                hi = mid;
                continue;
            }
            for (int i = len - (sz - idx++); i < len - 1; i++, idx++) {
                if (arr[i] < arr[i - 1]) {
                    lo = mid + 1;
                    stop = true;
                    break;
                }
                if (arr[i] <= arr[idx]) {
                    hi = mid;
                    stop = true;
                    break;
                }
            }
            if (!stop) {
                if (arr[len - 2] <= arr[len - 1]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return lo;
    }
};

int main() {
    Solution s;
}