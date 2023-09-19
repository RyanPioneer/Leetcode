/**
 * Source: https://rb.gy/46zjh
 * Date: 2023/9/19
 * Skill:
 * Runtime: 173 ms, faster than 95.32% of C++ online submissions
 * Memory Usage: 84.46 MB, less than 22.83% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class StockSpanner {
    stack<pairs> prices;
public:
    StockSpanner() {}

    int next(int price) {
        int cur_num = 1;
        while (!prices.empty() && prices.top().first <= price) {
            cur_num += prices.top().second;
            prices.pop();
        }
        prices.push({price, cur_num});
        return cur_num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {

}