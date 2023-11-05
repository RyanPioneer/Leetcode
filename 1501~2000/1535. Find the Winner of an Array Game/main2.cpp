/**
 * Source: t.ly/OLx61
 * Date: 2023/11/5
 * Skill:
 * Runtime: 87 ms, faster than 59.26% of C++ online submissions
 * Memory Usage: 63.51 MB, less than 40.28% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int sz = arr.size(), mx = arr[0], cur_num = arr[0], win_num = 0;
        for (int i = 1; i < sz; i++) {
            mx = max(mx, arr[i]);
            if (cur_num > arr[i]) {
                win_num++;
            } else {
                cur_num = arr[i];
                win_num = 1;
            }
            if (win_num == k) return cur_num;
        }
        return mx;
    }
};


int main() {
    Solution s;
}