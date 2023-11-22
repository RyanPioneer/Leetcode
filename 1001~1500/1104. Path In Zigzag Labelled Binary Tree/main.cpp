/**
 * Source: twtr.to/M3zsJ
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.46 MB, less than 98.99% of C++ online submissions
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
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int n = 1, num = 1, total = 1;
        while (total < label) {
            n++;
            num *= 2;
            total += num;
        }
        int real_pos = (n % 2 == 0 ? label : total - num + total - label + 1);
        while (n--) {
            if (n % 2 == 1) {
                res.push_back(real_pos);
            } else {
                int dis = total - real_pos;
                int fake_pos = total - num + dis + 1;
                res.push_back(fake_pos);
            }
            real_pos /= 2;
            total -= num;
            num /= 2;
        }
        reverse(begin(res), end(res));
        return res;
    }
};