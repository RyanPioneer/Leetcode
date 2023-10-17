/**
 * Source: twtr.to/JX2-F
 * Date: 2023/10/17
 * Skill:
 * Runtime: 25 ms, faster than 96.96% of C++ online submissions
 * Memory Usage: 33.89 MB, less than 54.26% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int indegree[10001] = {0}, root = -1;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1)
                indegree[leftChild[i]]++;
            if (rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) {
                if (root == -1)
                    root = i;
                else
                    return false;
            }
        int visited[10001] = {0};
        function<bool(int)> dfs;
        dfs = [&](int node) {
            if (node == -1)
                return true;
            if (visited[node] == 1)
                return false;
            visited[node] = 1;
            if (!dfs(leftChild[node]))
                return false;
            if (!dfs(rightChild[node]))
                return false;
            return true;
        };

        if (!dfs(root))
            return false;
        for (int i = 0; i < n; i++)
            if (visited[i] == 0)
                return false;
        return true;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}