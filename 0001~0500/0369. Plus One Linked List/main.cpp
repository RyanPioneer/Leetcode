/**
 * Source: tinyurl.com/23vftu4f
 * Date: 2025/4/8
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 12.47 MB, less than 16.15% of C++ online submissions
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* plusOne(ListNode* head)
    {
        function<int(ListNode*)> dfs = [&](ListNode* node) -> int {
            if (!node) {
                return 1;
            }
            int carry = dfs(node->next);
            int sum = node->val + carry;
            node->val = sum % 10;
            return sum / 10;
        };
        int carry = dfs(head);
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};
