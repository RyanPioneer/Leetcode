/**
 * Source: ibit.ly/Qq_34
 * Date: 2023/9/28
 * Skill:
 * Runtime: 67 ms, faster than 78.21% of C++ online submissions
 * Memory Usage: 29.04 MB, less than 44.13% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> arr;
        for (int i = 0; i < restaurants.size(); i++) {
            if ((veganFriendly == 0 || restaurants[i][2] == veganFriendly) && restaurants[i][3] <= maxPrice &&
                restaurants[i][4] <= maxDistance)
                arr.push_back({restaurants[i][1], restaurants[i][0]});
        }
        sort(begin(arr), end(arr), [](vector<int>& i, vector<int>& j) {
            if (i[0] == j[0])
                return i[1] > j[1];
            else
                return i[0] > j[0];
        });
        vector<int> res;
        for (auto i: arr)
            res.push_back(i[1]);
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {7,6}};
}