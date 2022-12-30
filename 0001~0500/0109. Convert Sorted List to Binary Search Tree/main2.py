"""
Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
Date: 2022/12/16
Skill: 
Runtime: 107 ms, faster than 100% 
Memory Usage: 20.3 MB, less than 30.38%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in head is in the range [0, 2 * 10^4].
    -10^5 <= Node.val <= 10^5
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def getMid(root):
            slow = root
            fast = root
            while fast and fast.next:
                fast = fast.next.next
                slow = slow.next
            root1 = root
            while root:
                if root.next == slow:
                    break
                root = root.next
            if root:
                root.next = None
            return root1, slow
    
        def traverse(node):
            if node == None:
                return None
            left, mid = getMid(node)
            if left == mid:
                root = TreeNode(mid.val)
                return root
            root = TreeNode(mid.val)
            root.left = traverse(left)
            root.right = traverse(mid.next)
            return root
        
        return traverse(head)