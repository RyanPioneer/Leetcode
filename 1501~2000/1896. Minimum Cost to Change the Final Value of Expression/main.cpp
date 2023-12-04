/**
 * Source: is.gd/fsAJZP
 * Date: 2023/12/4
 * Skill:
 * Ref:
 * Runtime: 52 ms, faster than 95.45% of C++ online submissions
 * Memory Usage: 15.72 MB, less than 93.18% of C++ online submissions
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
public:
    int minOperationsToFlip(string expression) {
        stack<array<int, 3>> st;
        int num = 0, res = 0;
        for (auto &c: expression) {
            if (c == '0' || c == '1') {
                num = c - '0';
                res = 1;
                if (!st.empty() && st.top()[2] < 2) {
                    array<int, 3> prev = st.top();
                    st.pop();
                    if (prev[2] == 0) { // 0: |
                        if (num == 0 && prev[0] == 0) {
                            res = 1;
                        } else if (num == 1 && prev[0] == 1){
                            res = 2;
                        } else {
                            res = 1;
                        }
                        num = prev[0] | num;
                    } else { // 1: &
                        if (num == 1 && prev[0] == 1) {
                            res = 1;
                        } else if (num == 0 && prev[0] == 0) {
                            res = 2;
                        } else {
                            res = 1;
                        }
                        num = prev[0] & num;
                    }
                }
            } else if (c == '&' || c == '|') {
                int op = c == '|' ? 0 : 1;
                st.push({num, res, op});
            } else if (c == '(') {
                st.push({num, res, 2});
            } else {
                st.pop();
                if (!st.empty() && st.top()[2] < 2) {
                    array<int, 3> prev = st.top();
                    st.pop();
                    if (prev[2] == 0) { // 0: |
                        if (num == 0 && prev[0] == 0) {
                            res = min(res, prev[1]);
                        } else if (num == 1 && prev[0] == 1){
                            res = min(res, prev[1]) + 1;
                        } else {
                            res = 1;
                        }
                        num = prev[0] | num;
                    } else { // 1: &
                        if (num == 1 && prev[0] == 1) {
                            res = min(res, prev[1]);;
                        } else if (num == 0 && prev[0] == 0) {
                            res = min(res, prev[1]) + 1;
                        } else {
                            res = 1;
                        }
                        num = prev[0] & num;
                    }
                }
            }
        }
        return res;
    }
};