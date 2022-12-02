"""
Source: https://leetcode.com/problems/add-two-numbers/
Date: 2022/2/18
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9

"""

from typing import Optional

# *Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num = l1.val + l2.val
        head = ListNode(num%10)
        num = int(num/10)
        node = head
        l1 = l1.next
        l2 = l2.next
        while l1 != None or l2 != None or num != 0:
            if l1 != None:
                num += l1.val
                l1 = l1.next
            if l2 != None:
                num += l2.val
                l2 = l2.next
            new_node = ListNode(num%10)
            num = int(num/10)
            node.next = new_node
            node = new_node
        return head