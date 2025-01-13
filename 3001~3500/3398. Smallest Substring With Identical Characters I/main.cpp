/**
 * Source: ibit.ly/3qhi6
 * Date: 2025/1/5
 * Skill:
 * Ref:
 * Runtime: 867 ms, faster than 9.11% of C++ online submissions
 * Memory Usage: 90.29 MB, less than 55.67% of C++ online submissions
 * Time complexity: WA
 * Space complexity:
 * Constraints:
 *      1 <= n == s.length <= 1000
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
    int minLength(string s, int numOps) {
        int len = s.size(), left = 0, right = 0;
        priority_queue<int> maxHeap;
        int prev = s[0] - '0', curLen = 1;
        for (int i = 1; i < len; i++) {
            if ((s[i] - '0') == prev) {
                curLen++;
            } else {
                if (curLen == i) {
                    left = curLen; 
                } else {
                    maxHeap.push(curLen);
                }
                curLen = 1;
                prev = 1 - prev;
            }
        }
        right = curLen;
        while (numOps--) {
            int top = maxHeap.empty() ? 0 : maxHeap.top();
            int mx = max({left, right, top});
            if (mx <= 1) break;
            if (left >= top && left >= right) {
                maxHeap.push(left / 2 - ((left + 1) % 2));
                left = left / 2;
            } else if (right >= top && right >= left) {
                maxHeap.push(right / 2 - ((right + 1) % 2));
                right = right / 2;
            } else if (top > 2) {
                maxHeap.pop();
                maxHeap.push(top / 2);
                maxHeap.push(top / 2 - ((top + 1) % 2));
            }
        }
        return max({1, left, right, maxHeap.empty() ? 0 : maxHeap.top()});
    }
};
