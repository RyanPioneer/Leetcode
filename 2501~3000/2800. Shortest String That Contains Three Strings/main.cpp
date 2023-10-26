/**
 * Source: tinyurl.com/ynddlcfw
 * Date: 2023/10/26
 * Skill:
 * Runtime: 51 ms, faster than 97.27% of C++ online submissions
 * Memory Usage: 20.96 MB, less than 93.92% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= a.length, b.length, c.length <= 100
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


class Solution {
    int dp[3][3];
    int find_len(string head, string tail) {
        int num = 0, len1 = head.length(), len2 = tail.length();
        for (int i = max(0, len1 - len2); i < len1; i++) {
            int j = i;
            while (j < len1 && head[j] == tail[j - i]) j++;
            if (j == len1) {
                num = max(num, len1 - i);
                break;
            }
        }
        return num;
    }
public:
    string minimumString(string a, string b, string c) {
        string res = a + b + c;
        int mx = res.length();
        string cand[3] = {a, b, c};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1;
                if (i == j) continue;
                int k = 3 - i - j;
                if (cand[i].find(cand[j]) != std::string::npos && cand[i].find(cand[k]) != std::string::npos)
                    return cand[i];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                int k = 3 - i - j;
                string tmp;
                if (cand[i].find(cand[j]) != std::string::npos) {
                    tmp = cand[i];
                } else {
                    int num1 = (dp[i][j] != -1 ? dp[i][j] : (dp[i][j] = find_len(cand[i], cand[j])));
                    tmp = cand[i] + cand[j].substr(num1);
                }
                if (tmp.find(cand[k]) == std::string::npos) {
                    int num2 = find_len(tmp, cand[k]);
                    tmp += cand[k].substr(num2);
                }
                if (mx > tmp.length() || (mx == tmp.length() && res > tmp)) {
                    mx = tmp.length();
                    res = tmp;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}