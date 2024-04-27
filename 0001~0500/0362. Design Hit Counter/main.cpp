/**
 * Source: tinyurl.com/27h4nrce
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.18 MB, less than 15.13% of C++ online submissions
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
typedef pair<int, int> PII;


class HitCounter {
public:
    deque<PII> q;
    int total;

    HitCounter() {
        total = 0;
    }

    void hit(int timestamp) {
        while (!q.empty() && timestamp - q.front().first >= 300) {
            total -= q.front().second;
            q.pop_front();
        }
        total += 1;
        if (!q.empty() && timestamp == q.back().first) {
            q.back().second++;
        } else {
            q.push_back({timestamp, 1});
        }
    }

    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front().first >= 300) {
            total -= q.front().second;
            q.pop_front();
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */