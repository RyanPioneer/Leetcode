/**
 * Source: is.gd/BJbfVk
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 49 ms, faster than 95.30% of C++ online submissions
 * Memory Usage: 36.03 MB, less than 45.51% of C++ online submissions
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


class Logger {
    unordered_map<string, int> mp;
public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.find(message) == end(mp) || mp[message] + 10 <= timestamp) {
            mp[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */