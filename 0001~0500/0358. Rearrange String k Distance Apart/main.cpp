/**
 * Source: t.ly/Fk1NM
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 78.47% of C++ online submissions
 * Memory Usage: 12.80 MB, less than 62.50% of C++ online submissions
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
typedef pair<int, char> PIC;

const int MX = 26;


class Solution {
public:
    string rearrangeString(string s, int k) {
        string res;
        priority_queue<PIC> pq;
        queue<PIC> q;
        int cnt[MX] = {0};

        for (auto &c: s) cnt[c - 'a']++;
        for (int i = 0; i < MX; i++) {
            if (cnt[i] > 0) {
                pq.push({cnt[i], 'a' + i});
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (!q.empty() && i - q.front().first >= k) {
                auto [time, c] = q.front();
                pq.push({cnt[c - 'a'], c});
                q.pop();
            }
            if (pq.empty()) return "";
            auto [count, c] = pq.top();
            res.push_back(c);
            if (count > 1) {
                q.push({i, c});
            }
            cnt[c - 'a']--;
            pq.pop();
        }
        return res;
    }
};