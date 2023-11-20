/**
 * Source: twtr.to/n_YNZ
 * Date: 2023/11/20
 * Skill:
 * Runtime: 165 ms, faster than 70.54% of C++ online submissions
 * Memory Usage: 102.84 MB, less than 13.30% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
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


const int MX = 1e5+1;


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0, prev[3] = {0}, cur_garbage[3] = {0}, presum[MX] = {0};
        for (int i = 0; i < travel.size(); i++) presum[i + 1] = presum[i] + travel[i];
        for (int i = 0; i < garbage.size(); i++) {
            for (auto &c: garbage[i]) {
                if (c == 'M') cur_garbage[0]++;
                if (c == 'P') cur_garbage[1]++;
                if (c == 'G') cur_garbage[2]++;
                res++;
            }
            for (int j = 0; j < 3; j++) {
                if (cur_garbage[j] > 0) {
                    res += presum[i] - presum[prev[j]];
                    prev[j] = i;
                }
                cur_garbage[j] = 0;
            }
        }
        return res;
    }
};