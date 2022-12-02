"""
Source: https://leetcode.com/problems/merge-two-sorted-lists/
Date: 2022/2/19
Constraints: 
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
"""

from typing import List

#* Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None and list2 == None:
            return None
        elif list1 == None:
            return list2
        elif list2 == None:
            return list1
        else:
            if list1.val < list2.val:
                head = ListNode(list1.val)
                list1 = list1.next
            else:
                head = ListNode(list2.val)
                list2 = list2.next
            node = head
            while list1 != None and list2 != None:
                if list1.val < list2.val:
                    new_node = ListNode(list1.val)
                    node.next = new_node
                    node = new_node
                    list1 = list1.next
                else:
                    new_node = ListNode(list2.val)
                    node.next = new_node
                    node = new_node
                    list2 = list2.next
            while list1 != None:
                new_node = ListNode(list1.val)
                node.next = new_node
                node = new_node
                list1 = list1.next
            while list2 != None:
                new_node = ListNode(list2.val)
                node.next = new_node
                node = new_node
                list2 = list2.next
            return head
                
        