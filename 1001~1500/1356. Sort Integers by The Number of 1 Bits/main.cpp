/**
 * Source: ibit.ly/NL3Ge
 * Date: 2023/10/30
 * Skill:
 * Runtime: 3 ms, faster than 96.58% of C++ online submissions
 * Memory Usage: 10.41 MB, less than 66.29% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e4+1;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int bit_cnt[MX] = {0};
        for (auto i: arr) bit_cnt[i] = __builtin_popcount(i);
        sort(arr.begin(), arr.end(), [&](int &a, int &b) {
            if (bit_cnt[a] == bit_cnt[b]) return a < b;
            else return bit_cnt[a] < bit_cnt[b];
        });
        return arr;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}