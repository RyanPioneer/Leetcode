/**
 * Source: ibit.ly/n2dOS
 * Date: 2024/6/27
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.37 MB, less than 64.44% of C++ online submissions
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


// Definition of commonSetBits API.
int commonSetBits(int num);


class Solution {
public:
    int findNumber() {
        int res = 0;
        for (int i = 0; i < 30; i++) {
            int n1 = 1 << i, n2 = 0;
            int cnt1 = commonSetBits(n1), cnt2 = commonSetBits(0);
            if (cnt1 > cnt2) {
                res += n1;
            }
        }
        return res;
    }
};