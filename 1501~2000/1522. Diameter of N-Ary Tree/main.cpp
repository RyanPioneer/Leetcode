/**
 * Source: tinyurl.com/22ke3gsc
 * Date: 2025/4/20
 * Skill:
 * Ref:
 * Runtime: 10 ms, faster than 78.05% of C++ online submissions
 * Memory Usage: 14.74 MB, less than 28.78% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    int diameter(Node* root) {
        int res = 0;
        function<int(Node*)> dfs = [&](Node* node) {
            if (!node) return 0;
            int max1 = 0, max2 = 0;
            for (auto child : node->children) {
                int depth = dfs(child);
                if (depth > max1) {
                    max2 = max1;
                    max1 = depth;
                } else if (depth > max2) {
                    max2 = depth;
                }
            }
            res = max(res, max1 + max2);
            return max1 + 1;
        };
        dfs(root);
        return res;
    }
};
