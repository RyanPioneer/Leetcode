/**
 * Source: ibit.ly/4Egog
 * Date: 2023/10/29
 * Skill:
 * Runtime: 2 ms, faster than 53.09% of C++ online submissions
 * Memory Usage: 6.74 MB, less than 8.64% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int time = minutesToTest / minutesToDie + (minutesToTest % minutesToDie != 0);
        int lo = 0, hi = 10;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pow((time + 1), mid) >= buckets) hi = mid;
            else lo = mid + 1;
        }
        return hi;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3,4,5};
}