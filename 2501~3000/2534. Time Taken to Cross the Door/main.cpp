/**
 * Source: ibit.ly/5N1Eb
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 74 ms, faster than 86.18% of C++ online submissions
 * Memory Usage: 80.25 MB, less than 72.36% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        queue<int> enter, exist;
        vector<int> res(arrival.size());
        int time, prev = 0, idx = 0, n = arrival.size();
        for (time = 0; time <= arrival.back() || !exist.empty() || !enter.empty(); time++) {
            while (idx < n && arrival[idx] == time) {
                if (state[idx] == 0) {
                    enter.push(idx);
                } else {
                    exist.push(idx);
                }
                idx++;
            }
            if (!enter.empty() && (exist.empty() || prev == 1)) {
                int cur = enter.front();
                enter.pop();
                res[cur] = time;
                prev = 1;
            } else if (!exist.empty() && (enter.empty() || prev != 1)) {
                int cur = exist.front();
                exist.pop();
                res[cur] = time;
                prev = -1;
            } else {
                prev = 0;
            }
        }
        return res;
    }
};