/**
 * Source: t.ly/ejRvI
 * Date: 2025/3/9
 * Skill: 
 * Ref:
 * Runtime: 139 ms, faster than 46.77% of C++ online submissions
 * Memory Usage: 214.91 MB, less than 69.35% of C++ online submissions
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
 
 
class Solution {
public:
    long long maxProfit(vector<int>& workers, vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [](vector<int> &a, vector<int> &b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        ll total = 0, mx = 0;
        unordered_map<int, int> mp;
        for (auto &i: workers) {
            mp[i]++;
        }
           
        for (auto &i: tasks) {
            if (mp[i[0]] > 0) {
                total += i[1];
                mp[i[0]]--;
            } else {
                mx = max(mx, (ll)i[1]);
            }
        }
        return total + mx;
    }
};
