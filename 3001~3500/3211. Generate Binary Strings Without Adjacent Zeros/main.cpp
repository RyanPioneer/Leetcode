/**
 * Source: jpeg.ly/HKmAi
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 99.11% of C++ online submissions
 * Memory Usage: 17.96 MB, less than 91.15% of C++ online submissions
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
const int MOD = 1e9+7;


class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> s1, s2;
        s1.insert(s1.end(), {"0", "1"});
        for (int i = 2; i <= n; i++) {
            s2.clear();
            for (auto& s : s1) {
                if (s.back() == '0') s2.push_back(s + "1");
                else {
                    s2.push_back(s + "0");
                    s2.push_back(s + "1");
                }
            }
            s1 = s2;
        }
        return s1;
    }
};
