/**
 * Source: ibit.ly/cHev8
 * Date: 2023/10/29
 * Skill:
 * Runtime: 19 ms, faster than 90.59% of C++ online submissions
 * Memory Usage: 11.45 MB, less than 23.31% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#define ll long long

class Solution {
public:
    long long countVowels(string word) {
        ll res = 0, sz = word.length();
        for (int i = 0; i < sz; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                res += (i + 1) * (sz - i);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}