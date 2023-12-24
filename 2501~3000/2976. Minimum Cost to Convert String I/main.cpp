/**
 * Source: is.gd/IwFbEv
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 155 ms, faster than 77.78% of C++ online submissions
 * Memory Usage: 87.80 MB, less than 22.22% of C++ online submissions
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
#define ll long long
#define SZ(X) ((int)(X).size())


class Solution {
    int dis[26][26];
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        fill(dis[0], dis[25] + 26, INT32_MAX / 2);
        for (int i = 0; i < 26; i++) dis[i][i] = 0;
        for (int i = 0; i < SZ(original); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dis[from][to] = min(dis[from][to], cost[i]);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (j == k) continue;
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < source.length(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (dis[from][to] > 1e8) return -1;
            res += dis[from][to];
        }
        return res;
    }
};