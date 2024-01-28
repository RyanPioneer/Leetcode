/**
 * Source: jpeg.ly/CJb4L
 * Date: 2024/1/27
 * Skill:
 * Ref:
 * Runtime: 69 ms, faster than 79.06% of C++ online submissions
 * Memory Usage: 44.92 MB, less than 40.57% of C++ online submissions
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
    vector<long long> countOfPairs(int n, int x, int y) {
        x--;
        y--;
        vector<ll> res(n, 0), presum(n + 1, 0);
        if (x == y) {
            for (int i = 0; i < n; i++) {
                presum[0]++;
                presum[i + 1]--;
                presum[1]++;
                presum[n - i]--;
            }
        } else {
            if (x > y) swap(x, y);
            for (int i = 0; i < n; i++) {
                // left
                if (i < x) {
                    presum[1]++;
                    presum[i + 1]--;
                    presum[1]++;
                    presum[x - i + 1]--;
                } else {
                    int dis = min(i - x, abs(i - y) + 1);
                    presum[dis]++;
                    presum[dis + x + 1]--;
                }
                // right
                if (i > y) {
                    presum[1]++;
                    presum[n - i]--;
                    presum[1]++;
                    presum[i - y + 1]--;
                } else {
                    int dis = min(y - i, abs(i - x) + 1);
                    presum[dis]++;
                    presum[dis + (n - y)]--;
                }
                // mid
                int len = y - x - 1;
                if (i < x) {
                    int left = x - i;
                    presum[left + 1]++;
                    presum[left + 1 + (len + 1)/ 2]--;
                    presum[left + 2]++;
                    presum[left + 2 + len / 2]--;
                } else if (i > y) {
                    int right = i - y;
                    presum[right + 1]++;
                    presum[right + 1 + (len + 1)/ 2]--;
                    presum[right + 2]++;
                    presum[right + 2 + len / 2]--;
                } else {
                    presum[0]++;
                    presum[1]++;
                    presum[(len + 2) / 2 + 1]--;
                    presum[(len + 1) / 2 + 1]--;
                    presum[min(abs(i - x), abs(i - y) + 1)]--;
                    presum[min(abs(i - x), abs(i - y) + 1) + 1]++;
                    presum[min(abs(i - y), abs(i - x) + 1)]--;
                    presum[min(abs(i - y), abs(i - x) + 1) + 1]++;
                }
            }
        }
        ll cur_num = presum[0];
        for (int i = 1; i < n; i++) {
            cur_num += presum[i];
            res[i - 1] = cur_num;
        }
        return res;
    }
};