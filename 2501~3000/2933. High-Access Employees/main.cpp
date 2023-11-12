/**
 * Source: t.ly/SBLOq
 * Date: 2023/11/12
 * Skill:
 * Runtime: 65 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 44.44 MB, less than 50.00% of C++ online submissions
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

typedef pair<int, int> pairs;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> res;
        unordered_map<string, vector<pairs>> employees;
        for (auto &i: access_times) {
            int hour = stoi(i[1].substr(0, 2));
            int second = stoi(i[1].substr(2, 2));
            employees[i[0]].push_back({hour, second});
        }
        for (auto &i: employees) {
            if (i.second.size() < 3) continue;
            sort(begin(i.second), end(i.second));
            for (int j = 2; j < i.second.size(); j++) {
                int h1 = i.second[j-2].first;
                int h2 = i.second[j].first;
                int s1 = i.second[j-2].second;
                int s2 = i.second[j].second;
                if (h1 == h2 || (h2 == h1 + 1 && s1 > s2)) {
                    res.push_back(i.first);
                    break;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}