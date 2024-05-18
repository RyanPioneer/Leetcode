/**
 * Source: is.gd/ToeTuB
 * Date: 2024/5/16
 * Skill:
 * Ref:
 * Runtime: 88 ms, faster than 96.84% of C++ online submissions
 * Memory Usage: 26.44 MB, less than 97.42% of C++ online submissions
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


class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();

        function<bool(int, string &)> check = [&](int idx, string &sub) {
            for (int i = 0; i < n; i++) {
                if (i == idx) continue;
                if (arr[i].find(sub) != string::npos) {
                    return false;
                }
            }
            return true;
        };

        vector<string> res;
        for (int i = 0; i < n; i++) {
            string ans;
            for (int len = 1; len <= arr[i].length() && ans.empty(); len++) {
                for (int j = 0; j + len <= arr[i].length(); j++) {
                    string sub = arr[i].substr(j, len);
                    if (check(i, sub) && (ans.empty() || sub < ans)) {
                        ans = sub;
                    }
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};