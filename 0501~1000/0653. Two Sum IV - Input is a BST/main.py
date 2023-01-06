"""
Source: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
Date: 2023/1/6
Skill:
Runtime: 90 ms, faster than 75.11%
Memory Usage: 16.3 MB, less than 81.93%
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
        stack, mySet = [root], set()
        while stack:
            if stack[-1].left:
                stack.append(stack[-1].left)
                stack[-2].left = None
                continue
            cur = stack.pop()
            if k-cur.val in mySet: return True
            mySet.add(cur.val)
            if cur.right: stack.append(cur.right)

        return False

if __name__ == "__main__":
    s = Solution
    left = TreeNode(2)
    root = TreeNode(5, left)
    print(s.findTarget(s, root, 3))