/**
 * Source: t.ly/ocgdV
 * Date: 2024/5/2
 * Skill:
 * Ref:
 * Runtime: 127 ms, faster than 70.91% of C++ online submissions
 * Memory Usage: 89.01 MB, less than 74.55% of C++ online submissions
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

const int MX = 2e4+2;

class BIT {
public:
    int arr[MX] = {0};

    void update(int idx, int num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }

    int query_presum(int idx) {
        int num = 0;
        while (idx > 0) {
            num += arr[idx];
            idx -= idx & -idx;
        }
        return num;
    }
};


class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        BIT *tree = new BIT();

        for (int i = 1; i <= n; i++) {
            tree->update(i, 1);
        }

        for (int i = 0; i < n; i++) {
            tree->update(bulbs[i], -1);
            // check before
            int left = bulbs[i] - k - 1;
            if (left > 0 && tree->query_presum(bulbs[i]) - tree->query_presum(left) == k) {
                if (tree->query_presum(left) - tree->query_presum(left - 1) == 0) {
                    return i + 1;
                }
            }

            // check after
            int right = bulbs[i] + k + 1;
            if (right <= n && tree->query_presum(right - 1) - tree->query_presum(bulbs[i]) == k) {
                if (tree->query_presum(right) - tree->query_presum(right - 1) == 0) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};