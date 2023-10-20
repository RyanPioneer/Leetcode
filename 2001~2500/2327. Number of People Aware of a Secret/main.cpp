/**
 * Source: tinyurl.com/ynurzkqb
 * Date: 2023/10/20
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.50 MB, less than 10.58% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n <= 1000
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll mod = 1e9+7, cur_people = 1, cur_talk = 0;
        vector<ll> add_talk_people(n + 1, 0), delete_people(n + 1, 0);
        add_talk_people[1 + delay]++;
        if (1 + forget <= n)
            delete_people[1 + forget]++;
        for (int i = 2; i <= n; ++i) {
            cur_talk = (cur_talk + add_talk_people[i] - delete_people[i]) % mod;
            if (i + delay <= n)
                add_talk_people[i + delay] += cur_talk;
            if (i + forget <= n)
                delete_people[i + forget] += cur_talk;
            cur_people = (cur_people + cur_talk - delete_people[i]) % mod;
        }
        return (cur_people + mod) % mod;
    }
};


int main() {
    Solution s;
    int res = s.peopleAwareOfSecret(6,2,5);
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}