/**
 * Source: ibit.ly/01gl0
 * Date: 2023/11/17
 * Skill:
 * Runtime: 246 ms, faster than 21.82% of C++ online submissions
 * Memory Usage: 6.91 MB, less than 61.82% of C++ online submissions
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

const int MX = 8;

class Solution {
    double feasible = 0, total = 0;
    int cnt1[MX], cnt2[MX], ball_type;
    int comb[MX][MX] = {1};
public:
    double getProbability(vector<int>& balls) {
        ball_type = balls.size();
        for (int i = 1; i < MX; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, MX - 1); j++) {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
        }
        dfs(0, balls);
        return feasible / total;
    }
    void dfs(int idx, vector<int>& balls) {
        if (idx == ball_type) {
            int total1 = 0, total2 = 0, kind1 = 0, kind2 = 0;
            long long combination = 1;
            for (int i = 0; i < ball_type; i++) {
                total1 += cnt1[i];
                total2 += cnt2[i];
                kind1 += (cnt1[i] > 0 ? 1 : 0);
                kind2 += (cnt2[i] > 0 ? 1 : 0);
                combination *= comb[cnt1[i] + cnt2[i]][cnt1[i]];
            }
            if (total1 != total2) return;
            total += combination;
            if (kind1 == kind2) feasible += combination;
            return;
        }
        for (int num = 0; num <= balls[idx]; num++) {
            cnt1[idx] = num;
            cnt2[idx] = balls[idx] - num;
            dfs(idx + 1, balls);
        }
    }
};


int main() {
    Solution s;
}