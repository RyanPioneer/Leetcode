/**
 * Source: is.gd/9jOKTp
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 511 ms, faster than 79.27% of C++ online submissions
 * Memory Usage: 166.36 MB, less than 80.49% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 16;


class Solution {
    vector<int> nums;
    vector<char> op;
    unordered_set<int> dp[MX][MX];
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                int j = i;
                while (i + 1 < s.length() && isdigit(s[i + 1])) i++;
                int num = stoi(s.substr(j, i - j + 1));
                nums.push_back(num);
            } else {
                op.push_back(s[i]);
            }
        }
        int n = SZ(nums), res = 0;
        dfs(0, n - 1);
        int ans = calculate(n);
        for (auto &i: answers) {
            if (i == ans) res += 5;
            else if (dp[0][n - 1].find(i) != end(dp[0][n - 1])) res += 2;
        }
        return res;
    }
    void dfs(int start, int end) {
        if (!dp[start][end].empty()) return;
        if (start == end) {
            dp[start][end].insert(nums[start]);
        } else {
            for (int mid = start; mid < end; mid++) {
                dfs(start, mid);
                dfs(mid + 1, end);
                for (auto &n1: dp[start][mid]) {
                    for (auto &n2: dp[mid + 1][end]) {
                        if (op[mid] == '+' && n1 + n2 <= 1000) {
                            dp[start][end].insert(n1 + n2);
                        }
                        if (op[mid] == '*' && n1 * n2 <= 1000) {
                            dp[start][end].insert(n1 * n2);
                        }
                    }
                }
            }
        }
    }
    int calculate(int n) {
        stack<int> st;
        st.push(nums[0]);
        for (int i = 0; i < n - 1; i++) {
            if (op[i] == '+') st.push(nums[i + 1]);
            else st.top() *= nums[i + 1];
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};