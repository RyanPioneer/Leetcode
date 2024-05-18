/**
 * Source: ibit.ly/FFH_3
 * Date: 2024/5/15
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 88.89% of C++ online submissions
 * Memory Usage: 17.57 MB, less than 76.77% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = *min_element(begin(sweetness), end(sweetness));
        int right = accumulate(begin(sweetness), end(sweetness), 0);

        while (left < right) {
            int mid = (left + right + 1) / 2;
            int piece = 0;
            for (int i = 0, total = 0; i < sweetness.size(); i++) {
                total += sweetness[i];
                if (total >= mid) {
                    total = 0;
                    piece++;
                }
            }
            if (piece > k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};