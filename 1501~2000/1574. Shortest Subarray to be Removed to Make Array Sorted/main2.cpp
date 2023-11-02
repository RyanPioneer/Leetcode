/**
 * Source: t.ly/0Aocf
 * Date: 2023/11/2
 * Skill:
 * Runtime: 70 ms, faster than 99.04% of C++ online submissions
 * Memory Usage: 67.06 MB, less than 78.21% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int sz = arr.size();
        int res = sz - 1, right = sz - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) right--;
        if (right == 0) return 0;
        res = right;
        for (int i = 0; i < sz; i++) {
            while (right < sz && arr[i] > arr[right]) right++;
            res = min(res, right - i - 1);
            if (i + 1 < sz && arr[i + 1] < arr[i]) break;
        }
        return res;
    }
};

int main() {
    Solution s;
}