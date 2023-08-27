/**
 * Source: https://rb.gy/45idc
 * Date: 2023/8/27
 * Skill:
 * Runtime: 53 ms, faster than 99.43% of C++ online submissions
 * Memory Usage: 74.08 MB, less than 7.14% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= tasks.length <= 2000
 *      1 <= starti, endi <= 2000
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class BIT {
    vector<int> nums;
    int size;
public:
    BIT(vector<int> arr) {
        nums = arr;
        size = arr.size() - 1;
    }

    void update_delta(int idx, int delta) {
        while (idx < size) {
            nums[idx] += delta;
            idx += (idx & -idx);
        }
    }

    int query_presum(int idx) {
        int res = 0;
        while (idx> 0) {
            res += nums[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    int query_range_sum(int left, int right) {
        return query_presum(right) - query_presum(left - 1);
    }
};


bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int sz = tasks.size(), res = 0;
        vector<int> nums (2002, 0);
//        sort(tasks.begin(), tasks.end(), cmp);
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        BIT tree(nums);
        for (int i = 0; i < sz; i++) {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            int prev_num = tree.query_range_sum(start, end);
            if (prev_num >= duration)
                continue;
            res += duration - prev_num;
            for (int j = 0; j < duration - prev_num; j++) {
                while (tree.query_range_sum(end, end) > 0)
                    end -= 1;
                tree.update_delta(end, 1);
            }
        }
        return res;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    printf("999");
}