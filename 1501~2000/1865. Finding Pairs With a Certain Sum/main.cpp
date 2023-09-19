/**
 * Source: t.ly/w1_8_
 * Date: 2023/9/19
 * Skill:
 * Runtime: 208 ms, faster than 63.05% of C++ online submissions
 * Memory Usage: 74.13 MB, less than 51.86% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums1.length <= 1000
 *      At most 1000 calls are made to add and count each.
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> num2cnt2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto i: nums2)
            num2cnt2[i]++;
    }

    void add(int index, int val) {
        num2cnt2[this->nums2[index]]--;
        this->nums2[index] += val;
        num2cnt2[this->nums2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (int i = 0; i < nums1.size(); i++)
            if (num2cnt2.find(tot - nums1[i]) != num2cnt2.end())
                cnt += num2cnt2[tot - nums1[i]];
        return cnt;
    }
};


int main() {

}