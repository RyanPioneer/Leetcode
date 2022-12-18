"""
Source: https://leetcode.com/problems/delete-node-in-a-linked-list/
Date: 2022/12/8
Skill: 
Runtime: 45 ms, faster than 86.52% 
Memory Usage: 14.2 MB, less than 92.26%
Time complexity: 
Space complexity: 
Constraints: 
    The number of the nodes in the given list is in the range [2, 1000].
"""

from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next