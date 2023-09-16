/**
 * Source: https://rb.gy/ao5e4
 * Date: 2023/9/16
 * Skill:
 * Runtime: TLE
 * Memory Usage:
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int primePalindrome(int n) {
        string s = to_string(n);
        int lo = pow(10, s.length() / 2), limit = 1e8 * 2, res = INT32_MAX;
        unordered_set<int> prime_set = find_prime(n);
        for (int i = lo; i < 2000; i++) {
            for (int type = 0; type < 2; type++) {
                int num = get_palin(i, type);
                if (num >= n && prime_set.find(num) != prime_set.end())
                    res = min(res, num);
            }
        }
        return res;
    }
    unordered_set<int> find_prime(int n) {
        vector<bool> visited(2 * 1e8 + 1, false);
        for (int i = 2; i <= sqrt(2 * 1e8); i++) {
            if (visited[i])
                continue;
            int j = i * i;
            while (j <= 2 * 1e8) {
                visited[j] = true;
                j += i;
            }
        }
        unordered_set<int> prime_set;
        for (int i = n; i <= 2 * 1e8; i++)
            if (!visited[i])
                prime_set.insert(i);
        return prime_set;
    }
    int get_palin(int num, int type) {
        int res = num;
        if (type == 0)
            num /= 10;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
    int res = s.primePalindrome(13);
    cout << res << endl;
}