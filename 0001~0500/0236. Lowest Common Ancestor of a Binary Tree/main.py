"""
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Date: 2022/12/28
Skill:
Runtime: 78 ms, faster than 81.1%
Memory Usage: 26.2 MB, less than 65.15%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [2, 10^5].
    -10^9 <= Node.val <= 10^9
    All Node.val are unique.
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ans = None

        def dfs(root):
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)
            mid = root.val == p.val or root.val == q.val
            if mid + left + right == 2: self.ans = root
            return left or right or mid

        dfs(root)
        return self.ans

# if __name__ == "__main__":