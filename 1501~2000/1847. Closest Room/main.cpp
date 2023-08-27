/**
 * Source: https://rb.gy/yt1wj
 * Date: 2023/8/27
 * Skill:
 * Runtime: 968 ms, faster than 10.96% of C++ online submissions
 * Memory Usage: 148.6 MB, less than 90.97% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= rooms.length <= 10 ** 5
 *      1 <= queries.length <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define pii pair<int,int>

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(rooms.begin(), rooms.end(), [](vector<int>& i, vector<int>& j){
            return i[1] > j[1];
        });
        int sz = rooms.size(), pos = 0;
        vector<int> res(queries.size(), -1);
        sort(queries.begin(), queries.end(), [](vector<int>& i, vector<int>& j) {
           return i[1] > j[1];
        });
        set<int> id;
        for (int i = 0; i < queries.size(); ++i) {
            while (pos < sz && rooms[pos][1] >= queries[i][1]) {
                id.insert(rooms[pos][0]);
                pos += 1;
            }
            if (id.size() > 0) {
                if (id.find(queries[i][0]) != id.end()) {
                    res[queries[i][2]] = queries[i][0];
                } else if (queries[i][0] > *prev(id.end())) {
                    res[queries[i][2]] = *prev(id.end());
                } else {
                    auto pos = lower_bound(id.begin(), id.end(), queries[i][0]);
                    int diff1 = *pos - queries[i][0], diff2 = INT32_MAX;
                    if (pos != id.begin())
                        diff2 =  queries[i][0] - *prev(pos);
                    res[queries[i][2]] = diff1 < diff2 ? *pos : *prev(pos);
                }
            }
        }
        return res;
    }
};

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
    Solution s;

}