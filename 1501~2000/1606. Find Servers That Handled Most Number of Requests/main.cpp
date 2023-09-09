/**
 * Source: https://rb.gy/2iik1
 * Date: 2023/9/8
 * Skill:
 * Runtime: 307 ms, faster than 78.21% of C++ online submissions
 * Memory Usage: 118.08 MB, less than 73.15% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> res, servers(k, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>busy;
        set<int> free;
        for (int i = 0; i < k; i++)
            free.insert(i);
        for (int i = 0; i < arrival.size(); i++) {
            int start = arrival[i];
            while (busy.size() > 0 && busy.top().first <= start) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.size() == 0)
                continue;
            auto pos = free.lower_bound(i % k);
            if (pos == end(free))
                pos = begin(free);
            servers[*pos]++;
            busy.push(make_pair(start + load[i], *pos));
            free.erase(*pos);
        }
        int maximun = *max_element(begin(servers), end(servers));
        for (int i = 0; i < k; i++)
            if (servers[i] == maximun)
                res.push_back(i);
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> nums{2,3,6};

}