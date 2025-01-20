/**
 * Source: jpeg.ly/zCrek
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 791 ms, faster than 70.45% of C++ online submissions
 * Memory Usage: 310.72 MB, less than 63.64% of C++ online submissions
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
const int MX = 1e5+10;


class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        multiset<int> lower, upper;
        ll upperSum = 0, lowerSum = 0;
        for (int i = 0; i < k; i++) {
            insert(lower, upper, lowerSum, upperSum, nums[i]);
            reBalance(lower, upper, lowerSum, upperSum);
        }
        ll res = upperSum - *upper.begin() * upper.size() + *upper.begin() * lower.size() - lowerSum;

        for (int i = k; i < nums.size(); i++) {
            deleteNum(lower, upper, lowerSum, upperSum, nums[i - k]);
            reBalance(lower, upper, lowerSum, upperSum);
            insert(lower, upper, lowerSum, upperSum, nums[i]);
            reBalance(lower, upper, lowerSum, upperSum);
            res = min(res, static_cast<long long>(upperSum - *upper.begin() * upper.size() + *upper.begin() * lower.size() - lowerSum));
        }
        return res;
    }
    void insert(multiset<int>& lower, multiset<int>& upper, ll& lowerSum, ll& upperSum, int num) {
        if (upper.empty() || num >= *upper.begin()) {
            upper.insert(num);
            upperSum += num;
        } else {
            lower.insert(num);
            lowerSum += num;
        }
    }
    void deleteNum(multiset<int>& lower, multiset<int>& upper, ll& lowerSum, ll& upperSum, int num) {
        if (!upper.empty() && num >= *upper.begin()) {
            upper.erase(upper.find(num));
            upperSum -= num;
        } else {
            lower.erase(lower.find(num));
            lowerSum -= num;
        }
    }
    void reBalance(multiset<int>& lower, multiset<int>& upper, ll& lowerSum, ll& upperSum) {
        if (upper.size() > lower.size() + 1) {
            lower.insert(*upper.begin());
            lowerSum += *upper.begin();
            upperSum -= *upper.begin();
            upper.erase(upper.find(*upper.begin()));
        } else if (lower.size() > upper.size()) {
            upper.insert(*lower.rbegin());
            upperSum += *lower.rbegin();
            lowerSum -= *lower.rbegin();
            lower.erase(lower.find(*lower.rbegin()));
        }
    }
};
