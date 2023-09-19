/**
 * Source: https://rb.gy/wq918
 * Date: 2023/9/19
 * Skill:
 * Runtime: 27 ms, faster than 79.71% of C++ online submissions
 * Memory Usage: 71.23 MB, less than 5.76% of C++ online submissions
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
    int maximizeSum(vector<int>& nums, int k) {
        return *max_element(begin(nums), end(nums)) * k + k * (k - 1) / 2;
    }
};

int main() {

}