/**
 * Source: t.ly/dPPnR
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 17 ms, faster than 51.80% of C++ online submissions
 * Memory Usage: 15.66 MB, less than 20.86% of C++ online submissions
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
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node)
    {
        Node* res = nullptr;
        if (node->right) {
            res = node->right;
            while (res->left) {
                res = res->left;
            }
        } else {
            while (node->parent && node->parent->right == node) {
                node = node->parent;
            }
            if (node->parent) {
                res = node->parent;
            }
        }
        return res;
    }
};
