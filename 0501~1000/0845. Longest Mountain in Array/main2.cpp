/**
 * Source: ibit.ly/qnYbp
 * Date: 2023/10/4
 * Skill:
 * Runtime: 13 ms, faster than 70.89% of C++ online submissions
 * Memory Usage: 19 MB, less than 35.15% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0, inc = 0, dec = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1])
                inc = dec = 0;
            else if (arr[i] > arr[i - 1]) {
                dec = 0;
                if (i - 2 >= 0 && arr[i - 1] < arr[i - 2])
                    inc = 1;
                else
                    inc++;
            } else {
                dec++;
                if (inc > 0)
                    res = max(res, inc + dec + 1);
            }
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}