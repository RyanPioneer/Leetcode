/**
 * Source: is.gd/wRu8oT
 * Date: 2023/12/3
 * Skill:
 * Ref:
 * Runtime: 110 ms, faster than 49.22% of C++ online submissions
 * Memory Usage: 118.12 MB, less than 77.72% of C++ online submissions
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
    int minMoves(vector<int>& nums, int k) {
        vector<int> pos;
        for (int i = 0; i < SZ(nums); i++) {
            if (nums[i] == 1) {
                pos.push_back(i);
            }
        }
        int cur_sum = 0;
        for (int i = 0; i < k; i++) cur_sum += abs(pos[i] - pos[k / 2]);
        int res = cur_sum;
        for (int i = 0; i + k < SZ(pos); i++) {
            int mid = i + k / 2;
            cur_sum -= pos[mid] - pos[i];
            cur_sum += pos[i + k] - pos[mid + 1];
            cur_sum += (pos[mid + 1] - pos[mid]) * (k / 2);
            cur_sum -= (pos[mid + 1] - pos[mid]) * (k - k / 2 - 1);
            res = min(res, cur_sum);
        }
        for (int i = 0; i < k; i++) res -= abs(k / 2 - i);
        return res;
    }
};