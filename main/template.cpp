/**
 * Source: tinyurl.com/yrp5uzk4
 * Date: 2023/10/26
 * Skill:
 * Runtime: 338 ms, faster than 96.26% of C++ online submissions
 * Memory Usage: 140.80 MB, less than 71.17% of C++ online submissions
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

const int MX = 201;
vector<vector<int>> divisors(MX);
const int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}