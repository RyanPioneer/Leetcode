/**
 * Source: https://rb.gy/0bhl6
 * Date: 2023/9/4
 * Skill:
 * Runtime: 68 ms, faster than 5.28% of C++ online submissions
 * Memory Usage: 17.62 MB, less than 5.28% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy_head = new ListNode(0, head);
        while (true) {
            bool flag = true;
            ListNode **cur = &dummy_head;
            unordered_map<int, ListNode**>num2pos;
            num2pos[0] = cur;
            int cur_sum = 0;
            while (flag && (*cur)->next) {
                cur = &(*cur)->next;
                cout << (*cur)->val << endl;
                cur_sum += (*cur)->val;
                if (num2pos.find(cur_sum) != num2pos.end()) {
                    ListNode ** tmp = num2pos[cur_sum];
                    (*tmp)->next = (*cur)->next;
                    flag = false;
                } else
                    num2pos[cur_sum] = cur;
            }
            if (flag)
                break;
        }
        return dummy_head->next;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    ListNode *head = new ListNode(0);
//    ListNode *node = head;
//    node->next = new ListNode(2);
//    node = node->next;
//    node->next = new ListNode(-3);
//    node = node->next;
//    node->next = new ListNode(3);
//    node = node->next;
//    node->next = new ListNode(1);
    ListNode* res = s.removeZeroSumSublists(head);
}