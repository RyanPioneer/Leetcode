/**
 * Source: https://rb.gy/ixahj
 * Date: 2023/9/8
 * Skill:
 * Runtime: 239 ms, faster than 62.56% of C++ online submissions
 * Memory Usage: 107.1 MB, less than 46.05% of C++ online submissions
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


class TopVotedCandidate {
    unordered_map<int, int> time2leader;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int cur_max = 0, leader = 0;
        this->times = times;
        unordered_map<int, int> p2cnt;
        for (int i = 0; i < persons.size(); i++) {
            p2cnt[persons[i]]++;
            if (p2cnt[persons[i]] >= cur_max) {
                cur_max = p2cnt[persons[i]];
                leader = persons[i];
            }
            time2leader[times[i]] = leader;
        }
    }

    int q(int t) {
        return time2leader[*prev(upper_bound(begin(times), end(times), t))];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {

}