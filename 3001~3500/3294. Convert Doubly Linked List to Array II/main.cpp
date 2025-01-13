/**
 * Source: ibit.ly/Vf-qY
 * Date: 2024/10/3
 * Skill:
 * Ref:
 * Runtime: 20 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 17.16 MB, less than 73.44% of C++ online submissions
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


// Definition for doubly-linked list.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
};


class Solution {
public:
    vector<int> toArray(Node *node){
        vector<int> res;
        Node *left = node->prev;
        while (left) {
            res.push_back(left->val);
            left = left->prev;
        }
        reverse(begin(res), end(res));
        res.push_back(node->val);
        Node *right = node->next;
        while (right) {
            res.push_back(right->val);
            right = right->next;
        }
        return res;
    }
};