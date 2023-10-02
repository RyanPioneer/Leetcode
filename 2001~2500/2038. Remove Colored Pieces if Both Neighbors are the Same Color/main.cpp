/**
 * Source: ibit.ly/JfksV
 * Date: 2023/10/2
 * Skill:
 * Runtime: 26 ms, faster than 96.22% of C++ online submissions
 * Memory Usage: 13.78 MB, less than 11.45% of C++ online submissions
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
    bool winnerOfGame(string colors) {
        int cnt[2] = {0};
        int sz = colors.length();
        for (int i = 0; i < sz; i++) {
            if (i + 1 < sz && colors[i] == colors[i + 1]) {
                i = i + 2;
                while (i < sz && colors[i] == colors[i - 1])
                    cnt[colors[i++] - 'A']++;
                i--;
            }
        }
        return cnt[0] > cnt[1];
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}