/**
 * Source: jpeg.ly/hpvop
 * Date: 2023/12/12
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 82.74% of C++ online submissions
 * Memory Usage: 10.26 MB, less than 62.52% of C++ online submissions
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
    int maxProduct(vector<int>& nums) {
        int a = -1, b = -1;
        for (auto &i: nums) {
            if (i > a) {
                b = a;
                a = i;
            } else if (i > b) {
                b = i;
            }
        }
        return (a - 1) * (b - 1);
    }
};