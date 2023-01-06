"""
Source: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
Date: 2023/1/3
Skill:
Runtime: 3152 ms, faster than 63.25%
Memory Usage: 30.7 MB, less than 97.29%
Time complexity:
Space complexity:
Constraints:
    1 <= parenti, childi <= 10^5
"""

from typing import List, Optional
from collections import defaultdict

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        dict, child_sum = defaultdict(TreeNode), 0
        for parent, child, isLeft in descriptions:
            if parent not in dict: dict[parent] = TreeNode(parent)
            if child not in dict: dict[child] = TreeNode(child)
            child_sum += child
            if isLeft: dict[parent].left = dict[child]
            else: dict[parent].right = dict[child]

        return dict[sum(list(dict.keys()))-child_sum]


if __name__ == "__main__":
    s = Solution