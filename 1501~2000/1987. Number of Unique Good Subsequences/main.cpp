/**
 * Source: t.ly/mQteZ
 * Date: 2023/11/7
 * Skill:
 * Runtime: 24 ms, faster than 94.30% of C++ online submissions
 * Memory Usage: 12.68 MB, less than 67.45% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long


class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        ll mod = 1e9+7, one = 0, zero = 0;
        for (auto i: binary) {
            if (i == '0') zero = (one + zero) % mod;
            else one = (zero + one + 1) % mod;
        }
        return (one + zero + (binary.find("0") != -1 ? 1 : 0)) % mod;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    vector<int> nums{0, 1};
}