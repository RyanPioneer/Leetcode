/**
 * Source: tinyurl.com/256h9hct
 * Date: 2025/4/13
 * Skill:
 * Ref:
 * Runtime: 1813 ms, faster than 13.42% of C++ online submissions
 * Memory Usage: 299.22 MB, less than 32.90% of C++ online submissions
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
#define ll long long
const int MOD = 1e9 + 7, MX = 1e5 + 1;

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
    Node* findRoot(vector<Node*> tree) {}
};
