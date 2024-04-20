/**
 * Source: is.gd/9SwCac
 * Date: 2024/4/20
 * Skill:
 * Ref:
 * Runtime: 159 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 282.92 MB, less than 16.67% of C++ online submissions
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
const int MX = 5100;

class BIT {
public:
    int arr[MX] = {0};

    void update(int idx, int num) {
        while (idx < MX) {
            arr[idx] = max(num, arr[idx]);
            idx += idx & -idx;
        }
    }

    int query_max(int idx) {
        int num = INT32_MIN;
        while (idx > 0) {
            num = max(num, arr[idx]);
            idx -= idx & -idx;
        }
        return num;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        BIT *tree1 = new BIT(), *tree2 = new BIT();
        int res = -1;
        for (int i = 0; i < prices.size(); i++) {
            int n1 = tree1->query_max(prices[i] - 1);
            int n2 = tree2->query_max(prices[i] - 1);
            if (n2 > 0) {
                res = max(res, n2 + profits[i]);
            }
            if (n1 > 0) {
                tree2->update(prices[i], n1 + profits[i]);
            }
            tree1->update(prices[i], profits[i]);
        }
        return res;
    }
};