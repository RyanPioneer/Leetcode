"""
Source: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
Date: 2023/1/6
Skill: Python yield
Ref: shorturl.at/dxHTZ
Runtime: 175 ms, faster than 42.47%
Memory Usage: 20.1 MB, less than 22.49%
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
        def inOrder(node):
            if node:
                yield from inOrder(node.left)
                yield node.val
                yield from inOrder(node.right)

        def inOrderReversed(node):
            if node:
                yield from inOrderReversed(node.right)
                yield node.val
                yield from inOrderReversed(node.left)

        leftGenerator = inOrder(root)
        rightGenerator = inOrderReversed(root)

        left, right = next(leftGenerator), next(rightGenerator)
        while left < right:
            if left + right == k: return True
            if left + right < k: left = next(leftGenerator)
            else: right = next(rightGenerator)

        return False

if __name__ == "__main__":
    s = Solution
    left = TreeNode(2)
    root = TreeNode(5, left)
    print(s.findTarget(s, root, 3))