/**
 * Source: ibit.ly/OO0BL
 * Date: 2024/6/27
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 53.00% of C++ online submissions
 * Memory Usage: 8.88 MB, less than 54.84% of C++ online submissions
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
    vector<int> constructArray(int n, int k) {
        vector<int> res{1};
        int lo = 2, hi = n;
        while (k > 1) {
            res.push_back(hi--);
            k--;
            if (k == 1) {
                while (hi >= lo) {
                    res.push_back(hi--);
                }
                return res;
            } else {
                res.push_back(lo++);
                k--;
            }
        }
        while (hi >= lo) {
            res.push_back(lo++);
        }
        return res;
    }
};