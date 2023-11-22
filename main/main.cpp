/**
 * Source: twtr.to/Utrjs
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 97.08% of C++ online submissions
 * Memory Usage: 11.76 MB, less than 95.63% of C++ online submissions
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
#define ll long long
typedef pair<int, int> PII;
const int MX = 2 * 1e3 + 1;
ll mod = 1e9+7;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {

    }
};