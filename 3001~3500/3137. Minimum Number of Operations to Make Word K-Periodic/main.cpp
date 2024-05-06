/**
 * Source: t.ly/1FigT
 * Date: 2024/5/5
 * Skill:
 * Ref:
 * Runtime: 89 ms, faster than 25.00% of C++ online submissions
 * Memory Usage: 29.19 MB, less than 12.50% of C++ online submissions
 * Time complexity:
 * Space complexity:
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


class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int num = word.length() / k, mx = 1;
        unordered_map<string, int> mp;
        for (int i = 0; i < num; i++) {
            string s = word.substr(i * k, k);
            mp[s]++;
            mx = max(mx, mp[s]);
        }
        return num - mx;
    }
};