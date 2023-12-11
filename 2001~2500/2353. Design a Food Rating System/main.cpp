/**
 * Source: is.gd/mGWfe5
 * Date: 2023/12/9
 * Skill:
 * Ref:
 * Runtime: 401 ms, faster than 74.54% of C++ online submissions
 * Memory Usage: 155.86 MB, less than 93.06% of C++ online submissions
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


class FoodRatings {
    unordered_map<string, set<pair<int, string>> > c2f;
    unordered_map<string, pair<int, string>> f2c;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < SZ(foods); i++) {
            f2c[foods[i]] = {-ratings[i], cuisines[i]};
            c2f[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto [rat, cui] = f2c[food];
        f2c[food] = {-newRating, cui};
        c2f[cui].erase({rat, food});
        c2f[cui].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return c2f[cuisine].begin()->second;
    }
};