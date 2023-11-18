/**
 * Source: twtr.to/0izXp
 * Date: 2023/11/18
 * Skill:
 * Runtime: 12 ms, faster than 69.64% of C++ online submissions
 * Memory Usage: 12.96 MB, less than 18.11% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        int left = 0, right = arr.back(), sz = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            int total = 0;
            for (int i = 0; i < sz; i++) {
                if (arr[i] >= mid) {
                    total += mid * (sz - i);
                    break;
                }
                total += arr[i];
            }
            if (total >= target) right = mid;
            else left = mid + 1;
        }
        int total1 = 0, total2 = 0;
        for (int i = 0; i < sz; i++) {
            if (arr[i] >= left) {
                total1 += left * (sz - i);
                total2 += (left - 1) * (sz - i);
                break;
            }
            total1 += arr[i];
            total2 += arr[i];
        }
        return abs(total1 - target) < abs(total2 - target) ? left : left - 1;
    }
};