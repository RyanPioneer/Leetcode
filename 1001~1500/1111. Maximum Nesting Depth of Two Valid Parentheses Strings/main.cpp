/**
 * Source: twtr.to/Eqz41
 * Date: 2023/11/22
 * Skill: 平均分配給兩個group，肯定能讓深度最小
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.92 MB, less than 27.01% of C++ online submissions
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
    vector<int> maxDepthAfterSplit(string seq) {
        int a = 0, b = 0;
        vector<int> res;
        for (auto &c: seq) {
            if (c == '(') {
                if (a <= b) {
                    a++;
                    res.push_back(0);
                } else {
                    b++;
                    res.push_back(1);
                }
            } else {
                if (a >= b) {
                    a--;
                    res.push_back(0);
                } else {
                    b--;
                    res.push_back(1);
                }
            }
        }
        return res;
    }
};