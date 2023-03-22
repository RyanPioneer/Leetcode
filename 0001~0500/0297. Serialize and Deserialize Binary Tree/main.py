"""
Source: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Date: 2023/3/22
Skill:
Runtime: 122 ms, faster than 57.89%
Memory Usage: 20.1 MB, less than 83.62%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        string = ""
        q = deque([root])
        while q:
            node = q.popleft()
            if node:
                string += str(node.val) + ","
                q.append(node.left)
                q.append(node.right)
            else:
                string += "#,"

        return string

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        nodes, pos, sz = [], 0, len(data)
        while pos < sz:
            if data[pos] == "#":
                nodes.append(None)
            else:
                start = pos
                while data[pos + 1].isnumeric():
                    pos += 1
                nodes.append(TreeNode(int(data[start: pos + 1])))
            pos += 2

        pos, child, sz = 0, 1, len(nodes)
        while pos < sz:
            if nodes[pos]:
                nodes[pos].left = nodes[child]
                nodes[pos].right = nodes[child + 1]
                child += 2
            pos += 1

        return nodes[0]


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))


if __name__ == "__main__":
    ser = Codec()
    deser = Codec()
    s = [1, 2, 3, None, None, 4, 5]
