/**
 * Source: https://rb.gy/3xpqp
 * Date: 2023/9/7
 * Skill:
 * Runtime: 4 ms, faster than 38.20% of C++ online submissions
 * Memory Usage: 7.5 MB, less than 12.22% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* pseudo_head = new ListNode(0, head);
        ListNode* l = pseudo_head;
        for (int i = 1; i < left; i++)
            l = l->next;
        ListNode* cur = l->next, *next = cur->next;
        for (int i = 1; i <= right - left; i++) {
            ListNode* tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        l->next->next = next;
        l->next = cur;
        return pseudo_head->next;
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
//    Solution s;
    string s = "1";
    cout << s[0] - '0';
}