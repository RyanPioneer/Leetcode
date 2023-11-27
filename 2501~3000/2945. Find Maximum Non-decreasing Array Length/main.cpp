/**
 * Source: is.gd/jLIsQ8
 * Date: 2023/11/27
 * Skill:
 * Ref:
 * Runtime: 291 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 133.46 MB, less than 25.00% of C++ online submissions
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
#define ll long long
const int MX = 1e5 + 2;


class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        nums.insert(begin(nums), 0);
        ll last_section_sum[MX] = {0}, last_len[MX] = {0}, presum[MX] = {0};
        for (int i = 1; i < SZ(nums); i++) presum[i] = presum[i - 1] + nums[i];
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i < SZ(nums); i++) {
            while (q.size() > 1 && presum[i] >= last_section_sum[*(begin(q) + 1)] + presum[*(begin(q) + 1)]) {
                q.pop_front();
            }
            last_section_sum[i] = presum[i] - presum[q.front()];
            last_len[i] = last_len[q.front()] + 1;
            while (!q.empty() && presum[i] + last_section_sum[i] <= last_section_sum[q.back()] + presum[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return last_len[SZ(nums) - 1];
    }
};