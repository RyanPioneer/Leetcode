/**
 * Source: is.gd/b05j0a
 * Date: 2023/12/2
 * Skill:
 * Ref:
 * Runtime: 75 ms, faster than 13.88% of C++ online submissions
 * Memory Usage: 29.33 MB, less than 9.79% of C++ online submissions
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
const int len = 4;


class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        return permute(cards, 0);
    }
    bool permute(vector<int>& cards, int idx) {
        if (idx == 4) {
            unordered_set<double> res = helper(cards, 0, len - 1);
            for (auto &i: res) {
                if (abs(i - 24.0) < 0.001) return true;
            }
            return false;
        }
        for (int i = idx; i < len; i++) {
            swap(cards[idx], cards[i]);
            if (permute(cards, idx + 1)) return true;
            swap(cards[idx], cards[i]);
        }
        return false;
    }
    unordered_set<double> helper(vector<int>& cards, int left, int right){
        if (left == right) return {(double)cards[left]};
        unordered_set<double> res;
        for (int i = left; i < right; i++) {
            for (auto &l: helper(cards, left, i)) {
                for (auto &r: helper(cards, i + 1, right)) {
                    for (auto &c: calculate(l, r)) {
                        res.insert(c);
                    }
                }
            }
        }
        return res;
    }
    unordered_set<double> calculate(double a, double b) {
        unordered_set<double> ans;
        ans.insert(a + b);
        ans.insert(a - b);
        ans.insert(a * b);
        if (b != 0.0) ans.insert(a / b);
        return ans;
    }
};