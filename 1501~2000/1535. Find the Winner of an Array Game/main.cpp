/**
 * Source: t.ly/OLx61
 * Date: 2023/11/5
 * Skill:
 * Runtime: 146 ms, faster than 6.02% of C++ online submissions
 * Memory Usage: 71.70 MB, less than 6.94% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 2 * 1e5 + 1;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int sz = arr.size(), bigger_after[MX], mx = 0;
        for (int i = 0; i < sz; i++) {
            mx = max(mx, arr[i]);
            arr.push_back(arr[i]);
            bigger_after[i] = bigger_after[i + sz] = 2 * sz;
        }
        stack<int> st;
        for (int i = 2 * sz - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) bigger_after[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < sz; i++) {
            int num = (i > 0 && arr[i] > arr[i - 1] ? 1 : 0);
            if (bigger_after[i] - i + num > k) {
                return arr[i];
            }
        }
        return mx;
    }
};


int main() {
    Solution s;
}