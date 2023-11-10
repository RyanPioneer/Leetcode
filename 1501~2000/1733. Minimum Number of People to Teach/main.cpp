/**
 * Source: t.ly/Lq0vR
 * Date: 2023/11/10
 * Skill:
 * Runtime: 168 ms, faster than 98.75% of C++ online submissions
 * Memory Usage: 61.86 MB, less than 80.00% of C++ online submissions
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
#include <bitset>
#include <functional>
#include <list>


using namespace std;

#define ll long long

typedef pair<int, int> pairs;

const int MX = 501;


class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int cnt[MX] = {0}, people[MX][MX] = {0}, init[MX][MX] = {0}, m = languages.size(), res = INT32_MAX;
        for (int i = 0; i < m; i++) {
            for (auto &j: languages[i]) {
                people[i + 1][j] = 1;
                init[i + 1][j] = 1;
            }
        }
        for (auto &i: friendships) {
            bool find = false;
            for (int j = 1; j <= n; j++) {
                if (init[i[0]][j] == 1 && init[i[1]][j] == 1) {
                    find = true;
                    break;
                }
            }
            if (find) continue;
            for (int j = 1; j <= n; j++) {
                for (auto &k: i) {
                    if (people[k][j] == 0) {
                        cnt[j]++;
                        people[k][j] = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            res = min(res, cnt[i]);
        }
        return res;
    }
};


int main() {
    Solution s;

}