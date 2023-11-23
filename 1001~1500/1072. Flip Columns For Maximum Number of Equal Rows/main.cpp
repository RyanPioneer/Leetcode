/**
 * Source: is.gd/rfccdb
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 139 ms, faster than 97.55% of C++ online submissions
 * Memory Usage: 64.69 MB, less than 93.25% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class TrieNode {
public:
    TrieNode * next[2];
    int num = 0;
};

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = SZ(matrix), n = SZ(matrix[0]), res = 1;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < m; i++) {
            int add = matrix[i][0] == 1 ? 1 : 0;
            TrieNode *node = root;
            for (int j = 0; j < n; j++) {
                int nx = (matrix[i][j] + add) % 2;
                if (node->next[nx] == nullptr) node->next[nx] = new TrieNode();
                node = node->next[nx];
            }
            node->num++;
            res = max(res, node->num);
        }
        return res;
    }
};