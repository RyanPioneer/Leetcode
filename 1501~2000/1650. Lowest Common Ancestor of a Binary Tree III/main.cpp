/**
 * Source: ibit.ly/Nlepy
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 74.55% of C++ online submissions
 * Memory Usage: 12.88 MB, less than 65.28% of C++ online submissions
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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p, *b = q;
        while (a != b) {
            a = a->parent == nullptr ? q : a->parent;
            b = b->parent == nullptr ? p : b->parent;
        }
        return a;
    }
};