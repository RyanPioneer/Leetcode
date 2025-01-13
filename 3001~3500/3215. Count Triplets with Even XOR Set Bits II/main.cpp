/**
 * Source: ibit.ly/VRVNH
 * Date: 2024/8/16
 * Skill: 遇到 bit manipulation 問題可以先畫在紙上觀察數字間的關係！
 * Ref:
 * Runtime: 174 ms, faster than 72.64% of C++ online submissions
 * Memory Usage: 153.83 MB, less than 29.25% of C++ online submissions
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
    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        ll odd[3] = {0}, even[3] = {0};
        for (auto &i: a) {
            int num = __builtin_popcount(i);
            if (num % 2) odd[0]++;
            else even[0]++;
        }
        for (auto &i: b) {
            int num = __builtin_popcount(i);
            if (num % 2) {
                odd[1] += even[0];
                even[1] += odd[0];
            } else {
                odd[1] += odd[0];
                even[1] += even[0];
            }
        }
        for (auto &i: c) {
            int num = __builtin_popcount(i);
            if (num % 2) {
                odd[2] += even[1];
                even[2] += odd[1];
            } else {
                odd[2] += odd[1];
                even[2] += even[1];
            }
        }
        return even[2];
    }
};