"""
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Date: 2022/12/31
Skill: Iterative without parent pointers
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

    # Three static flags to keep track of post-order traversal.

    # Both left and right traversal pending for a node.
    # Indicates the nodes children are yet to be traversed.
    BOTH_PENDING = 2
    # Left traversal done.
    LEFT_DONE = 1
    # Both left and right traversal done for a node.
    # Indicates the node can be popped off the stack.
    BOTH_DONE = 0

    def lowestCommonAncestor(self, root, p, q):


# if __name__ == "__main__":