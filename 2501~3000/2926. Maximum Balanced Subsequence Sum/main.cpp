/**
 * Source: t.ly/pvVJB
 * Date: 2023/11/5
 * Skill:
 * Runtime: 204 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 332.74 MB, less than 25.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long


const int MX = 1e5 + 1;

class BIT {
public:
    ll arr[MX] = {0};

    void update(int idx, ll num) {
        while (idx < MX) {
            arr[idx] = max(num, arr[idx]);
            idx += idx & -idx;
        }
    }

    ll query_max(int idx) {
        ll num = LLONG_MIN;
        while (idx > 0) {
            num = max(num, arr[idx]);
            idx -= idx & -idx;
        }
        return num;
    }
};


class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        // 離散化 nums[i] - i
        vector<int> a = nums;
        for (int i = 0; i < nums.size(); i++) a[i] -= i;
        sort(begin(a), end(a));
        a.erase(unique(begin(a), end(a)), end(a)); // remove duplicate element

        ll res = INT32_MIN;
        BIT *tree = new BIT();
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i] - i;
            int order = lower_bound(begin(a), end(a), num) - begin(a) + 1;
            ll n = tree->query_max(order);
            res = max(res, n + nums[i]);
            if (nums[i] > 0) tree->update(order, nums[i] + n);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}