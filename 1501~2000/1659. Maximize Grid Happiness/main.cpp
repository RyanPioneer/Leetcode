/**
 * Source: ibit.ly/VmC8E
 * Date: 2023/11/16
 * Skill:
 * Runtime: 515 ms, faster than 23.53% of C++ online submissions
 * Memory Usage: 6.80 MB, less than 100.00% of C++ online submissions
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


typedef pair<int, int> PII;

const int MX = 243;

class Solution {
    int n, people2val[3] = {0, 120, 40};
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        int dp[6][7][7][MX], res = INT32_MIN;
        const int MXSTATE = pow(3, n);
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= introvertsCount; j++) {
                for (int k = 0; k <= extrovertsCount; k++) {
                    for (int l = 0; l < MX; l++) {
                        dp[i][j][k][l] = INT32_MIN;
                    }
                }
            }
        }
        dp[0][0][0][0] = 0;
        for (int row = 1; row <= m; row++) {
            for (int intro = 0; intro <= introvertsCount; intro++) {
                for (int extro = 0; extro <= extrovertsCount; extro++) {
                    for (int state = 0; state < MXSTATE; state++) {
                        PII people = countPeople(state);
                        int prev_intro = intro - people.first, prev_extro = extro - people.second;
                        if (prev_intro < 0 || prev_extro < 0) continue;
                        for (int prev_state = 0; prev_state < MXSTATE; prev_state++) {
                            if (dp[row - 1][prev_intro][prev_extro][prev_state] == INT32_MIN) continue;
                            int val = countVal(state, prev_state);
                            dp[row][intro][extro][state] = max(dp[row][intro][extro][state], dp[row - 1][prev_intro][prev_extro][prev_state] + val);
                            if (row == m) res = max(res, dp[row][intro][extro][state]);
                        }
                    }
                }
            }
        }
        return res;
    }
    PII countPeople(int state) {
        PII people = {0, 0};
        while (state > 0) {
            if (state % 3 == 1) people.first++;
            if (state % 3 == 2) people.second++;
            state /= 3;
        }
        return people;
    }
    int countVal(int cur_state, int prev_state) {
        int val = 0, cur_num = 0;
        for (int i = 0; i < n; i++, cur_state /= 3, prev_state /= 3) {
            int n1 = cur_state % 3, n2 = prev_state % 3;
            val += people2val[n1];
            if (n1 == 1) {
                if (cur_num == 1) val -= 60;
                if (cur_num == 2) val -= 10;
                if (n2 == 1) val -= 60;
                if (n2 == 2) val -= 10;
            }
            if (n1 == 2) {
                if (cur_num == 1) val -= 10;
                if (cur_num == 2) val += 40;
                if (n2 == 1) val -= 10;
                if (n2 == 2) val += 40;
            }
            cur_num = n1;
        }
        return val;
    }
};


int main() {
    Solution s;
}