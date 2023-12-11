/**
 * Source: jpeg.ly/8SrNy
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 17.66 MB, less than 50.00% of C++ online submissions
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


class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0;
        for (int i = 0; i < SZ(batteryPercentages); i++) {
            if (batteryPercentages[i] <= res) continue;
            res++;
        }
        return res;
    }
};