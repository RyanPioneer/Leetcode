/**
 * Source: https://rb.gy/1yzmt
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 326 ms, faster than 83.17% of C++ online submissions
 * Memory Usage: 183.06 MB, less than 39.67% of C++ online submissions
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


class SnapshotArray {
    int snapId = 0;
    vector<map<int, int>> mp;
public:
    SnapshotArray(int length) {
        mp.resize(length);
    }

    void set(int index, int val) {
        mp[index][snapId] = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        if (mp[index].empty()) return 0;
        auto it = mp[index].upper_bound(snap_id);
        if (it == begin(mp[index])) return 0;
        else return prev(it)->second;
    }
};
