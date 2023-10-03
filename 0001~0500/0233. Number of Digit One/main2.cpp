/**
 * Source: ibit.ly/un7WT
 * Date: 2023/10/3
 * Skill:
 * Runtime: 2 ms, faster than 54.39% of C++ online submissions
 * Memory Usage: 6.54 MB, less than 7.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      0 <= n <= 10 ** 9
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
    int countDigitOne(int n) {
        if (n < 10)
            return n > 0;
        string str = to_string(n);
        int res = n / 10 + (str.back() != '0'), sz = str.length();
        if (str[0] == '1')
            res += stoi(str.substr(1)) + 1;
        else
            res += pow(10, sz - 1);
        for (int i = 1; i < sz - 1; i++) {
            if (str[i] - '1' > 0)
                res += (stoi(str.substr(0, i)) + 1) * pow(10, sz - i - 1);
            else if (str[i] - '1' == 0)
                res += stoi(str.substr(0, i)) * pow(10, sz - i - 1) + stoi(str.substr(i + 1, sz - i - 1)) + 1;
            else
                res += stoi(str.substr(0, i)) * pow(10, sz - i - 1);
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}