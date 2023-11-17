/**
 * Source: ibit.ly/rUz1x
 * Date: 2023/11/17
 * Skill:
 * Runtime: 14 ms, faster than 85.20% of C++ online submissions
 * Memory Usage: 10.99 MB, less than 58.60% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


typedef pair<int, int> PII;


class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<PII> st;
        for (auto &c: s) {
            if (st.empty() || c != st.back().first) {
                st.push_back({c, 1});
            } else {
                st.back().second++;
                if (st.back().second == k) st.pop_back();
            }
        }
        string res;
        for (auto &p: st) {
            auto &[c, time] = p;
            for (int i = 0; i < time; i++) res.push_back(c);
        }
        return res;
    }
};


int main() {
    Solution s;
}