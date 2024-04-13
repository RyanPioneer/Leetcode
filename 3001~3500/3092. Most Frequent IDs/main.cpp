/**
 * Source: is.gd/ssP3Co
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 459 ms, faster than 21.39% of C++ online submissions
 * Memory Usage: 239.91 MB, less than 5.00% of C++ online submissions
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


class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll> res;
        unordered_map<ll, unordered_set<int>> freq2num;
        unordered_map<ll, ll> num2freq;
        priority_queue<ll, vector<ll>> pq;
        for (int i = 0; i < nums.size(); i++) {
            if (num2freq.find(nums[i]) != num2freq.end()) {
                freq2num[num2freq[nums[i]]].erase(nums[i]);
            }
            num2freq[nums[i]] += freq[i];
            freq2num[num2freq[nums[i]]].insert(nums[i]);
            pq.push(num2freq[nums[i]]);
            while (!pq.empty() && freq2num[pq.top()].empty()) pq.pop();
            res.push_back(pq.top());
        }
        return res;
    }
};