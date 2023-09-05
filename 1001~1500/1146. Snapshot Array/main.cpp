/**
 * Source: https://rb.gy/1yzmt
 * Date: 2023/9/5
 * Skill:
 * Runtime: 452 ms, faster than 54.3% of C++ online submissions
 * Memory Usage: 193.8 MB, less than 19.45% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class SnapshotArray {
public:
    unordered_map<int, vector<pairs>> num_changes;
    int size, time;
    SnapshotArray(int length) {
        size = length;
        time = 0;
        for (int i = 0; i < length; i++)
            num_changes[i].push_back({0, 0});
    }

    void set(int index, int val) {
        if (num_changes[index].back().first < time)
            num_changes[index].push_back({time, val});
        else
            num_changes[index].back().second = val;
    }

    int snap() {
        time++;
        return time - 1;
    }

    int get(int index, int snap_id) {
        auto pos = lower_bound(begin(num_changes[index]), end(num_changes[index]), make_pair(snap_id, INT_MAX));
        return prev(pos)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
//    Solution s;
    vector<int> vec{0, 1};
    auto pos = lower_bound(begin(vec), end(vec), 2);
    cout << pos - begin(vec) << endl;
}