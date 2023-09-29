/**
 * Source: ibit.ly/_9idB
 * Date: 2023/9/29
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.73 MB, less than 30.08% of C++ online submissions
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
    string makeLargestSpecial(string s) {
        if (s.length() == 2)
            return s;
        vector<string> ss;
        for (int i = 0; i < s.length(); i++) {
            int i0 = i, count = 0;
            while (i < s.length()) {
                if (s[i] == '1')
                    count++;
                else
                    count--;
                if (count == 0)
                    break;
                i++;
            }
            ss.push_back("1" + makeLargestSpecial(s.substr(i0 + 1, i - i0 - 1)) + "0");
        }
        sort(ss.begin(), ss.end(), greater<string>());
        string res;
        for (auto i: ss)
            res += i;
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}