/**
 * Source: ibit.ly/9K0jT
 * Date: 2024/12/31
 * Skill:
 * Ref:
 * Runtime: 15 ms, faster than 81.25% of C++ online submissions
 * Memory Usage: 9.50 MB, less than 70.31% of C++ online submissions
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
    int maxSizedArray(long long s) {
        int lo = 1, hi = 100;
        if (s > 1e6) hi = 1e3;

        auto calculate_sum = [&](int dim) {
            ll total = 0;
            for (int i = 0; i < dim; i++) {
                for (int j = 0; j < dim; j++) {
                    for (int k = 0; k < dim; k++) {
                        total += (long long)i * (j | k);
                    }
                }
            }
            return total <= s;
        };
    
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (calculate_sum(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        return hi;
    }
};
