/**
 * Source: tinyurl.com/yt6353a3
 * Date: 2023/10/24
 * Skill:
 * Runtime: 43 ms, faster than 88.19% of C++ online submissions
 * Memory Usage: 9.04 MB, less than 96.39% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int visited[1001] = {0}, res = 0, arr[3];
        visited[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            res++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur_num = q.front();
                q.pop();
                for (auto &i: nums) {
                    arr[0] = cur_num + i, arr[1] = cur_num - i, arr[2] = cur_num ^ i;
                    for (int k = 0; k < 3; k++) {
                        int j = arr[k];
                        if (j == goal)
                            return res;
                        if (j >= 0 && j <= 1000 && visited[j] == 0) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}