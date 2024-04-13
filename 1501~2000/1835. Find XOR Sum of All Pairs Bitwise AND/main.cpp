/**
 * Source: https://rb.gy/0n3t3
 * Date: 2024/4/5
 * Skill:
 * Ref:
 * Runtime: 94 ms, faster than 79.12% of C++ online submissions
 * Memory Usage: 95.76 MB, less than 92.77% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(1)
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef unsigned long long ULL;

const int MX = 26;


class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int num = 0, res = 0;
        for (auto &i: arr2) num ^= i;
        for (auto &i: arr1) res ^= i & num;
        return res;
    }
};