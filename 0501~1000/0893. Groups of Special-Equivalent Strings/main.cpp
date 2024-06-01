/**
 * Source: t.ly/iyVUf
 * Date: 2024/5/31
 * Skill:
 * Ref:
 * Runtime: 51 ms, faster than 7.08% of C++ online submissions
 * Memory Usage: 11.87 MB, less than 75.22% of C++ online submissions
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

const int MX = 1e3+10;


class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size(), groups[MX], cnt[MX][2][26] = {0};
        for (int i = 0; i < n; ++i) groups[i] = i;

        function<int(int)> findGroups = [&](int idx) {
            if (groups[idx] != idx) {
                groups[idx] = findGroups(groups[idx]);
            }
            return groups[idx];
        };

        function<void(int, int)> mergeGroups = [&](int g1, int g2) {
            int f1 = findGroups(g1), f2 = findGroups(g2);
            if (f1 != f2) {
                groups[f1] = f2;
            }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].length(); j++) {
                if (j % 2) cnt[i][0][words[i][j]-'a']++;
                else cnt[i][1][words[i][j]-'a']++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool check = true;
                for (int k = 0; k < 2 && check; k++) {
                    for (int l = 0; l < 26 && check; l++) {
                        if (cnt[i][k][l] != cnt[j][k][l]) {
                            check = false;
                            break;
                        }
                    }
                }
                if (check) mergeGroups(i, j);
            }
        }

        unordered_set<int> res;
        for (int i = 0; i < n; i++) res.insert(findGroups(i));
        return res.size();
    }
};