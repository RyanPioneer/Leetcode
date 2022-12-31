"""
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Date: 2022/12/31
Skill: Iterative using parent pointers
Runtime: 70 ms, faster than 92.28%
Memory Usage: 18.7 MB, less than 93.71%
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
        stack = [root]
        dict = {root: None}
        while p not in dict or q not in dict:
            parent = stack.pop()
            if parent.left:
                dict[parent.left] = parent
                stack.append(parent.left)
            if parent.right:
                dict[parent.right] = parent
                stack.append(parent.right)

        p_ancestor, cur = set(), p
        while cur:
            p_ancestor.add(cur)
            cur = dict[cur]
        while q not in p_ancestor:
            q = dict[q]

        return q

# if __name__ == "__main__":