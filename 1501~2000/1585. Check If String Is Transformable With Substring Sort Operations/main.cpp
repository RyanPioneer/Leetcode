/**
 * Source: t.ly/kfSfM
 * Date: 2023/11/2
 * Skill:
 * Runtime: 39 ms, faster than 96.92% of C++ online submissions
 * Memory Usage: 23.22 MB, less than 26.15% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<int> next_pos[10];
        for (int i = s.length() - 1; i >= 0; i--) {
            next_pos[s[i] - '0'].push_back(i);
        }
        for (int i = 0; i < s.length(); i++) {
            int num = t[i] - '0';
            if (next_pos[num].empty()) return false;
            for (int j = 0; j < num; j++) {
                if (!next_pos[j].empty() && next_pos[j].back() < next_pos[num].back()) {
                    return false;
                }
            }
            next_pos[num].pop_back();
        }
        return true;
    }
};


int main() {
    Solution s;
}