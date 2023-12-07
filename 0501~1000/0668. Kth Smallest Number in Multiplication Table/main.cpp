/**
 * Source: is.gd/VIEx2Y
 * Date: 2023/12/7
 * Skill:
 * Ref:
 * Runtime: 10 ms, faster than 61.32% of C++ online submissions
 * Memory Usage: 6.24 MB, less than 66.32% of C++ online submissions
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


class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m < n) swap(m, n);
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) / 2, num = 0;
            for (int i = 1; i <= n && i <= mid; i++) {
                num += min(mid / i, m);
            }
            if (num >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};