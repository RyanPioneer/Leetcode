/**
 * Source: is.gd/ssP3Co
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 176 ms, faster than 98.77% of C++ online submissions
 * Memory Usage: 145.79 MB, less than 95.82% of C++ online submissions
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

#define ll long long
typedef pair<ll, ll> PLL;

const int MX = 1e5+10;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll> res;
        ll cnt[MX] = {0};
        priority_queue<PLL> pq;

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]] += freq[i];
            pq.push({cnt[nums[i]], nums[i]});
            while (!pq.empty()) {
                if (cnt[pq.top().second] != pq.top().first) {
                    pq.pop();
                    continue;
                }
                res.push_back(pq.top().first);
                break;
            }
        }
        return res;
    }
};