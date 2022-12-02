/** 
 * Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
 * Date: 2022/11/18
 * Skill: Two Pointers
 * Runtime: 45 ms, faster than 97.22%
 * Memory Usage: 14.7 MB, less than 33.45%
 * Time complexity: O(m+n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A ? A->next : headB;
            B = B ? B->next : headA;
        }
        return A;
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