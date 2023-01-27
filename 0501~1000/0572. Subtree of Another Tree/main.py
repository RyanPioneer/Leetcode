"""
Source: https://leetcode.com/problems/subtree-of-another-tree/
Date: 2023/1/26
Skill:
Runtime: 63 ms, faster than 99.35%
Memory Usage: 15.2 MB, less than 30.93%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        def find_subtree(node, subNode):
            if not node or not subNode:
                return node == subNode
            else:
                if node.val == subNode.val and find_subtree(node.left, subNode.left)\
                        and find_subtree(node.right, subNode.right):
                    return True
                if node.val == subRoot.val and find_subtree(node.left, subRoot.left)\
                        and find_subtree(node.right, subRoot.right):
                    return True
                if find_subtree(node.left, subRoot) or find_subtree(node.right, subRoot):
                    return True

                return False

        return find_subtree(root, subRoot)