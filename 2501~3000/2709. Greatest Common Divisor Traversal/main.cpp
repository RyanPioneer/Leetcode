/**
 * Source: https://rb.gy/0kbh0
 * Date: 2023/9/8
 * Skill:
 * Runtime: 329 ms, faster than 91.00% of C++ online submissions
 * Memory Usage: 127.93 MB, less than 59.37% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
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
    vector<int> father;
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        father.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            father[i] = i;
        vector<int> primes = find_prime(*max_element(begin(nums), end(nums)));
        unordered_set<int> prime_set(begin(primes), end(primes));
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (prime_set.find(num) != prime_set.end()) {
                groups[num].push_back(i);
                continue;
            }
            for (int j = 0; j < primes.size(); ++j) {
                if (num < primes[j])
                    break;
                if (prime_set.find(num) != prime_set.end()) {
                    groups[num].push_back(i);
                    break;
                }
                if (num % primes[j] == 0) {
                    groups[primes[j]].push_back(i);
                    while (num % primes[j] == 0)
                        num /= primes[j];
                }
            }
        }
        for (auto p: groups)
            for (int i = 0; i < p.second.size() - 1; i++)
                union_set(p.second[i], p.second[i + 1]);
        for (int i = 0; i < nums.size() - 1; i++)
            if (find_father(i) != find_father(i + 1))
                return false;
        return true;
    }
    vector<int> find_prime(int n) {
        vector<int> res;
        vector<int> visited(n + 1, false);
        for (int i = 2; i <= sqrt(n); i++) {
            if (!visited[i]) {
                for (int j = i * 2; j <= n; j += i)
                    visited[j] = true;
            }
        }
        for (int i = 2; i <= n; i++)
            if (!visited[i])
                res.push_back(i);
        return res;
    }
    int find_father(int x) {
        if (father[x] != x)
            father[x] = find_father(father[x]);
        return father[x];
    }
    void union_set(int x, int y) {
        int x_father = find_father(x), y_father = find_father(y);
        if (x_father != y_father)
            father[x_father] = y_father;
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
    int res = s.canTraverseAllPairs(nums);
    cout << res << endl;
}