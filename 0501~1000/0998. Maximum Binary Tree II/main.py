"""
Source: https://leetcode.com/problems/maximum-binary-tree-ii/
Date: 2022/12/28
Skill:
Runtime: 41 ms, faster than 80.81%
Memory Usage: 13.9 MB, less than 84.30%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 100].
    All the values of the tree are unique.
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        prev, cur = None, root
        while cur and val < cur.val:
            prev, cur = cur, cur.right

        node = TreeNode(val, cur, None)
        if prev: prev.right = node
        return root if prev is not None else node



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/





