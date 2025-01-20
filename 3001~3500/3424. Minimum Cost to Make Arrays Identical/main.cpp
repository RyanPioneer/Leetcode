/**
 * Source: jpeg.ly/X3JyW
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 65 ms, faster than 88.89% of C++ online submissions
 * Memory Usage: 189.30 MB, less than 44.44% of C++ online submissions
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
const int MX = 1e5+10;


class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        ll res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            res += abs(arr[i] - brr[i]);
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        for (int i = 0; i < n; i++) {
            k += abs(arr[i] - brr[i]);
        }
        return min(res, k);
    }
};
