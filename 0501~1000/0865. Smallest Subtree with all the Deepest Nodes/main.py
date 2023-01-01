"""
Source: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
Date: 2022/12/28
Skill:
Runtime: 41 ms, faster than 78.31%
Memory Usage: 14.1 MB, less than 92.86%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree will be in the range [1, 500].
    0 <= Node.val <= 500
    The value of each node in the tree is unique.
"""

from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root:
                return 0, None
            left_height, left = dfs(root.left)
            right_height, right = dfs(root.right)
            if left_height > right_height:
                return left_height+1, left
            elif left_height < right_height:
                return right_height+1, right
            else:
                return left_height+1, root

        return dfs(root)[1]
# if __name__ == "__main__":