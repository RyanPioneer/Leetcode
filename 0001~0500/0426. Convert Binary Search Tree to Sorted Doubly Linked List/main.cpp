/**
 * Source: ibit.ly/RIycS
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 75.61% of C++ online submissions
 * Memory Usage: 9.63 MB, less than 92.81% of C++ online submissions
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

const int MX = 16;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* mi = root, *mx = root;

        function<void(Node *)> dfs = [&](Node* cur) {
            if (!cur) return;

        };
    }
};