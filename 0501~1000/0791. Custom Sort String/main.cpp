/** 
 * Source: https://leetcode.com/problems/custom-sort-string/
 * Date: 2021/7/14
 * Constraints: 
 *      order has length at most 26, and no character is repeated in order.
 *      str has length at most 200.
 *      order and str consist of lowercase letters only.
 * Skill: Use std::sort
 * Lambda Function: [&] means all variables that you refer to are captured by reference, 
 * and [=] means they are captured by value.
 * Reference: https://www.cplusplus.com/reference/algorithm/sort/
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string customSortString(string order, string str) {
        sort(str.begin(), str.end(), [&](char a, char b) {return order.find(a) < order.find(b);});
        return str;
    }
};

int main() {
  
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();