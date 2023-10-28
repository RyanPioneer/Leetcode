/**
 * Source: tinyurl.com/yn238ual
 * Date: 2023/10/28
 * Skill:
 * Runtime: 179 ms, faster than 92.99% of C++ online submissions
 * Memory Usage: 76.30 MB, less than 97.56% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo = 0, hi = removable.size();
        int len = p.length(), sz = s.length();
        int pos[100001];
        for (int i = 0; i < sz; i++) pos[i] = 100001;
        for (int i = 0; i < removable.size(); i++) pos[removable[i]] = i;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2, idx = 0;
            for (int i = 0; i < sz; i++) {
                if (s[i] == p[idx] && (pos[i] >= mid)) {
                    idx++;
                    if (idx == len) break;
                }
            }
            if (idx == len) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
}