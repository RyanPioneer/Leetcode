"""
Source: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
Date: 2023/1/6
Skill:
Runtime: 299 ms, faster than 7.42%
Memory Usage: 16.3 MB, less than 95.59%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        left_stack, right_stack = [], []

        def pushLeft(cur):
            while cur:
                left_stack.append(cur)
                cur = cur.left

        def getLeft():
            cur = left_stack.pop()
            if cur.right:
                left_stack.append(cur.right)
                pushLeft(cur.right)
            return cur.val

        def pushRight(cur):
            while cur:
                right_stack.append(cur)
                cur = cur.right

        def getRight():
            cur = right_stack.pop()
            if cur.left:
                right_stack.append(cur.left)
                pushRight(cur.left)
            return cur.val

        pushLeft(root)
        pushRight(root)
        left, right = getLeft(), getRight()
        while left < right:
            if left + right == k:
                return True
            elif left + right > k:
                right = getRight()
            else:
                left = getLeft()

        return False




if __name__ == "__main__":
    s = Solution
    left = TreeNode(2)
    root = TreeNode(5, left)
    print(s.findTarget(s, root, 3))