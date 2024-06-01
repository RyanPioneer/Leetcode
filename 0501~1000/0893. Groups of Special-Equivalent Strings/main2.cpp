/**
 * Source: t.ly/iyVUf
 * Date: 2024/5/31
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 80.09% of C++ online submissions
 * Memory Usage: 11.85 MB, less than 75.22% of C++ online submissions
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


typedef pair<string, string> pss;


class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pss> s;
        for (auto &w: words) {
            pss p;
            for (int i = 0; i < w.length(); i++) {
                if (i % 2) p.first += w[i];
                else p.second += w[i];
            }
            sort(begin(p.first), end(p.first));
            sort(begin(p.second), end(p.second));
            s.insert(p);
        }
        return s.size();
    }
};