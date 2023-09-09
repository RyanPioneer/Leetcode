/**
 * Source: https://rb.gy/ixahj
 * Date: 2023/9/8
 * Skill:
 * Runtime: 226 ms, faster than 78.60% of C++ online submissions
 * Memory Usage: 110.41 MB, less than 7.21% of C++ online submissions
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
    map<int, int> res;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int cur_max = 0;
        unordered_map<int, int> p2cnt;
        map<int, int> res;
        for (int i = 0; i < persons.size(); i++) {
            p2cnt[persons[i]]++;
            if (p2cnt[persons[i]] >= cur_max) {
                cur_max = p2cnt[persons[i]];
                res[times[i]] = persons[i];
            }
        }
        this->res = res;
    }

    int q(int t) {
        return prev(res.upper_bound(t))->second;
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