/**
 * Source: is.gd/ZiQnqs
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 52.63% of C++ online submissions
 * Memory Usage: 19.82 MB, less than 29.82% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
ll mod = 1e9+7;
const int MX = 1e4+1;


class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        reverse(begin(arr1), end(arr1));
        reverse(begin(arr2), end(arr2));
        int len1 = SZ(arr1), len2 = SZ(arr2), carry = 0;
        for (int i = 0; i < max(len1, len2); i++) {
            if (i < len1) carry += arr1[i];
            if (i < len2) carry += arr2[i];
            int r = carry % -2;
            carry /= -2;
            if (r < 0) {
                r += 2;
                carry += 1;
            }
            res.push_back(r);
        }
        while (carry != 0) {
            int r = carry % -2;
            carry /= -2;
            if (r < 0) {
                r += 2;
                carry += 1;
            }
            res.push_back(r);
        }
        while (SZ(res) > 1 && res.back() == 0) res.pop_back();
        reverse(begin(res), end(res));
        return res;
    }
};