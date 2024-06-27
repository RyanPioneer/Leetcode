/**
 * Source: ibit.ly/t5J3M
 * Date: 2024/6/26
 * Skill:
 * Ref:
 * Runtime: 14 ms, faster than 24.17% of C++ online submissions
 * Memory Usage: 16.06 MB, less than 13.27% of C++ online submissions
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
    int smallestRepunitDivByK(int k) {
        int cnt = 1, num = 1;
        unordered_set<int> Set;
        while (1) {
            if (Set.find(num) != Set.end()) {
                break;
            }
            if (num % k == 0) {
                return cnt;
            }
            Set.insert(num);
            num = ((num * 10) + 1) % k;
            cnt++;
        }
        return -1;
    }
};