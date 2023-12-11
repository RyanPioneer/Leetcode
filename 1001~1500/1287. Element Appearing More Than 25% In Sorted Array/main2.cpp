/**
 * Source: jpeg.ly/b30yF
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 42.19% of C++ online submissions
 * Memory Usage: 12.68 MB, less than 92.26% of C++ online submissions
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
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int cand[3] = {arr[len / 4], arr[len / 2], arr[3 * len / 4]};
        for (int i = 0; i < 3; i++) {
            auto left = lower_bound(begin(arr), end(arr), cand[i]);
            auto right = upper_bound(begin(arr), end(arr), cand[i]);
            if (right - left > len / 4) return cand[i];
        }
        return arr[0];
    }
};