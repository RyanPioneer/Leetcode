/**
 * Source: is.gd/hJmjHz
 * Date: 2024/4/18
 * Skill:
 * Ref:
 * Runtime: 649 ms, faster than 67.01% of C++ online submissions
 * Memory Usage: 96.55 MB, less than 70.10% of C++ online submissions
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
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int len1 = nums1.size(), len2 = nums2.size();

        if (len1 > len2) return kthSmallestProduct(nums2, nums1, k);

        function<ll(ll)> check = [&](ll num) {
            ll cnt = 0;
            for (auto &i: nums1) {
                if (i == 0) {
                    if (num >= 0) {
                        cnt += len2;
                    }
                } else if (i > 0) {
                    // i * nums2[j] <= num => nums2[j] <= num / i
                    ll j = floor(num * 1.0 / i);
                    auto it = upper_bound(begin(nums2), end(nums2), j);
                    cnt += it - begin(nums2);
                } else {
                    // i * nums2[j] <= num => nums2[j] >= num / i
                    ll j = ceil(num * 1.0 / i);
                    auto it = lower_bound(begin(nums2), end(nums2), j);
                    cnt += end(nums2) - it;
                }
            }
            return cnt;
        };

        ll left = -1e10, right = 1e10;

        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (check(mid) >= k) right = mid;
            else left = mid + 1;
            cout << mid << endl;
        }
        return right;
    }
};