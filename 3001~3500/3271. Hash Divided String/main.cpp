/**
 * Source: jpeg.ly/zOw7v
 * Date: 2025/1/15
 * Skill:
 * Ref: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.24 MB, less than 38.03% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
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

#define ll long long


class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size(), pos = 0;
        string res;
        for (int i = 0; i < n/k; i++) {
            int hash = 0;
            for (int j = 0; j < k; j++) {
                hash += s[pos++] - 'a';
            }
            res += ('a' + hash % 26);
        }
        return res;
    }
};
