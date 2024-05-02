/**
 * Source: t.ly/SLxeP
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 45.45% of C++ online submissions
 * Memory Usage: 8.75 MB, less than 9.09% of C++ online submissions
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
    int newInteger(int n) {
        ll left = 1, right = LLONG_MAX / 2;
        stack<int> st;

        function<bool(ll)> check = [&](ll num) {
            st.push(num % 10);
            num /= 10;
            ll power = 1, total = 0;
            while (num) {
                st.push(num % 10);
                power *= 9;
                num /= 10;
            }
            while (!st.empty()) {
                int t = st.top();
                st.pop();
                if (t > 0) total += t * power;
                if (t == 9) break;
                power /= 9;
            }
            return total >= n;
        };

        while (left < right) {
            ll mid = (left + right) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }

        ll advance = 1;
        while (right) {
            if (right % 10 == 9) {
                left += advance;
                right += 1;
            }
            right /= 10;
            advance *= 10;
        }

        return left;
    }
};