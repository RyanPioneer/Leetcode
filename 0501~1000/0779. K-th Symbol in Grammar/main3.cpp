/**
 * Source: tinyurl.com/ypdrghxv
 * Date: 2023/10/25
 * Skill:
 * Runtime: 2 ms, faster than 51.37% of C++ online submissions
 * Memory Usage: 6.21 MB, less than 53.37% of C++ online submissions
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int kthGrammar(int n, int k) {
        int res = 0, total = pow(2, n - 2);
        for (int i = 1; i < n; i++) {
            if (k > total) {
                k -= total;
                res = (res + 1) % 2;
            }
            total /= 2;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3}, nums2{5,4,6,2,1,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}