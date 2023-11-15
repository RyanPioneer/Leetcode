/**
 * Source: ibit.ly/fyGsG
 * Date: 2023/11/15
 * Skill:
 * Runtime: 76 ms, faster than 69.40% of C++ online submissions
 * Memory Usage: 51.52 MB, less than 56.72% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
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
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr.back();
    }
};


int main() {
    Solution s;
}