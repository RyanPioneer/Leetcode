/**
 * Source: tinyurl.com/ypnegp2o
 * Date: 2023/10/26
 * Skill:
 * Runtime: 379 ms, faster than 89.17% of C++ online submissions
 * Memory Usage: 167.66 MB, less than 46.46% of C++ online submissions
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


class StockPrice {
    unordered_map<int, int> stocks;
    multiset<int> prices;
    int cur;
public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (stocks.find(timestamp) != stocks.end()) {
            prices.erase(prices.lower_bound(stocks[timestamp]));
        }
        prices.insert(price);
        stocks[timestamp] = price;
        cur = max(cur, timestamp);
    }

    int current() {
        return stocks[cur];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */


int main() {
}