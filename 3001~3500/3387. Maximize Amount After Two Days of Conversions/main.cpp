/**
 * Source: t.ly/cNnoQ
 * Date: 2025/2/1
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 88.77% of C++ online submissions
 * Memory Usage: 81.34 MB, less than 66.66% of C++ online submissions
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
typedef pair<string, double> psd;


class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<psd>> mp;

        for (int i = 0; i < pairs1.size(); i++) {
            mp[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            mp[pairs1[i][1]].push_back({pairs1[i][0], 1.0/rates1[i]});
        }

        unordered_map<string, double> mp1;
        mp1[initialCurrency] = 1.0;
        queue<string> q;
        q.push(initialCurrency);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (auto& [next, rate] : mp[cur]) {
                if (mp1.find(next) == mp1.end()) {
                    mp1[next] = mp1[cur] * rate;
                    q.push(next);
                }
            }
        }

        double res = 1.0;
        mp.clear();
        for (int i = 0; i < pairs2.size(); i++) {
            mp[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            mp[pairs2[i][1]].push_back({pairs2[i][0], 1.0/rates2[i]});
        }
        
        queue<psd> q2;
        unordered_set<string> visited;
        visited.insert(initialCurrency);
        q2.push({initialCurrency, 1.0});
        while (!q2.empty()) {
            auto [cur, rate] = q2.front();
            q2.pop();
            if (mp1.find(cur) != mp1.end()) {
                res = max(res, rate * mp1[cur]);
            }
            for (auto& [next, rate2] : mp[cur]) {
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q2.push({next, rate / rate2});
                }
            }
        }

        return res;
    }
};
