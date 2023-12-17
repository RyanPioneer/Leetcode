/**
 * Source: is.gd/KU0S9s
 * Date: 2023/12/15
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 67.86% of C++ online submissions
 * Memory Usage: 8.53 MB, less than 14.82% of C++ online submissions
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
    unordered_map<int, string> mp;
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        mp = {{1, "One "}, {2, "Two "}, {3, "Three "}, {4, "Four "},
              {5, "Five "}, {6, "Six "}, {7, "Seven "}, {8, "Eight "},
              {9, "Nine "}, {10, "Ten "}, {11, "Eleven "}, {12, "Twelve "},
              {13, "Thirteen "}, {14, "Fourteen "}, {15, "Fifteen "},
              {16, "Sixteen "}, {17, "Seventeen "}, {18, "Eighteen "},
              {19, "Nineteen "}, {20, "Twenty "}, {30, "Thirty "},
              {40, "Forty "}, {50, "Fifty "}, {60, "Sixty "},
              {70, "Seventy "}, {80, "Eighty "}, {90, "Ninety "},
              {100, "Hundred "}, {1000, "Thousand "}, {1000000, "Million "},
              {1000000000, "Billion "}};

        string res = helper(num);
        res.pop_back();
        return res;
    }
    string helper(int num) {
        if (num == 0) return "";
        if (mp.find(num) != end(mp)) {
            if (num < 100) return mp[num];
            else return "One " + mp[num];
        }
        if (num < 100) return helper(num - num % 10) + helper(num % 10);
        else if (num < 1000) return helper(num / 100) + mp[100] + helper(num % 100);
        else if (num < 1000000) return helper(num / 1000) + mp[1000] + helper(num % 1000);
        else if (num < 1000000000) return helper(num / 1000000) + mp[1000000] + helper(num % 1000000);
        else return helper(num / 1000000000) + mp[1000000000] + helper(num % 1000000000);
    }
};