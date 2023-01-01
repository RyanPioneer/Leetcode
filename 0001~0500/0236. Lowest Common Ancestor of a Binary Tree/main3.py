"""
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Date: 2022/12/31
Skill: Iterative without parent pointers
Runtime: 75 ms, faster than 84.40%
Memory Usage: 18.3 MB, less than 97.76%
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
    BOTH_PENDING = 2
    LEFT_DONE = 1
    BOTH_DONE = 0

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack = [(root, Solution.BOTH_PENDING)]
        one_node_found = False
        LCA_index = -1
        while stack:
            cur_node, cur_state = stack.pop()
            if cur_state != Solution.BOTH_DONE:
                if cur_state == Solution.BOTH_PENDING:
                    if cur_node == p or cur_node == q:
                        if one_node_found:
                            return stack[LCA_index][0]
                        else:
                            one_node_found = True
                            LCA_index = len(stack)
                    next_node = cur_node.left
                else:
                    next_node = cur_node.right
                stack.append((cur_node, cur_state - 1))
                if next_node: stack.append((next_node, Solution.BOTH_PENDING))
            else:
                if one_node_found and LCA_index == len(stack):
                    LCA_index -= 1

        return None


# if __name__ == "__main__":