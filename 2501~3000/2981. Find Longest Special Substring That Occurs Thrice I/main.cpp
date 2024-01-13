/**
 * Source: jpeg.ly/zrPVB
 * Date: 2024/1/6
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 89.02% of C++ online submissions
 * Memory Usage: 7.73 MB, less than 89.22% of C++ online submissions
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
#define ll long long
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;
ll mod = 1e9+7;


class Solution {
public:
    int maximumLength(string s) {
        int res = -1, len = s.length();
        map<pair<char, int>, int> mp;
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j < len && s[i] == s[j]) j++;
            int num = j - i;
            if (num >= 3) res = max(res, num - 2);
            if (num >= 2) {
                mp[{s[i], num - 1}] += 2;
                if (mp[{s[i], num - 1}] >= 3) res = max(res, num - 1);
            }
            mp[{s[i], num}]++;
            if (mp[{s[i], num}] >= 3) res = max(res, num);
            i = j - 1;
        }
        return res;
    }
};