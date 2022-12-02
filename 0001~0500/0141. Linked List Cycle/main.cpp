/** 
 * Source: https://leetcode.com/problems/linked-list-cycle/
 * Date: 2022/11/18
 * Skill: Two Pointers
 * Runtime: 18 ms, faster than 71.80%
 * Memory Usage: 7.9 MB, less than 81.31%
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      
 * 
 */

#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();