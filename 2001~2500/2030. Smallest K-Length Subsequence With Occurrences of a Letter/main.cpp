/**
 * Source: is.gd/kCgPHx
 * Date: 2024/4/18
 * Skill:
 * Ref:
 * Runtime: 161 ms, faster than 53.40% of C++ online submissions
 * Memory Usage: 33.42 MB, less than 80.58% of C++ online submissions
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
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int len = s.length();
        stack<char> st;
        int letter_num = 0, total_letter_num = 0;
        for (auto &c: s) total_letter_num += c == letter;
        for (int i = 0; i < len; i++) {
            while (!st.empty() && st.size() + len - i > k && s[i] < st.top()) {
                if (st.top() != letter || letter_num + total_letter_num > repetition) {
                    if (st.top() == letter) letter_num--;
                    st.pop();
                } else {
                    break;
                }
            }
            if (st.size() < k) {
                st.push(s[i]);
                if (s[i] == letter) letter_num++;
            } else if (s[i] == letter && letter_num + total_letter_num == repetition) {
                string ans;
                for (int j = 0; j < total_letter_num; j++) ans.push_back(letter);
                while (!st.empty()) {
                    if (st.top() == letter || total_letter_num == 0) {
                        ans.push_back(st.top());

                    } else if (st.top() != letter) {
                        total_letter_num--;
                    }
                    st.pop();
                }
                reverse(begin(ans), end(ans));
                return ans;
            }
            if (s[i] == letter) total_letter_num--;
        }

        string res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};