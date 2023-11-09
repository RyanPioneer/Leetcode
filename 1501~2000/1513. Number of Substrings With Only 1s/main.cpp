/**
 * Source: ibit.ly/z4JHb
 * Date: 2023/11/9
 * Skill:
 * Runtime: 10 ms, faster than 72.45% of C++ online submissions
 * Memory Usage: 9.07 MB, less than 79.61% of C++ online submissions
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

#define ll long long

typedef pair<int, int> pairs;

const int MX = 2 * 1e5 + 2;

class Solution {
public:
    int numSub(string s) {
        ll mod = 1e9+7, res = 0;
        int idx = -1, sz = s.length();
        while (++idx < sz) {
            while (idx < sz && s[idx] == '0') idx++;
            if (idx == sz) break;
            ll num = 1;
            while (idx + 1 < sz && s[idx] == s[idx + 1]) {
                idx++;
                num++;
            }
            res = (res + (1 + num) * num / 2) % mod;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}