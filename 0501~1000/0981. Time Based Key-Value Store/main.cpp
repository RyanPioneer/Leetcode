/**
 * Source: tinyurl.com/y239ptxl
 * Date: 2023/10/26
 * Skill:
 * Runtime: 292 ms, faster than 55.14% of C++ online submissions
 * Memory Usage: 131.69 MB, less than 17.13% of C++ online submissions
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


class TimeMap {
    unordered_map<string, map<int, string>> fmap;
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        fmap[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto iter = fmap[key].upper_bound(timestamp);
        if (iter == fmap[key].begin()) return "";
        return prev(iter)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


int main() {
//    Solution s;
}