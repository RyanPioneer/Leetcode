"""
Source: https://rb.gy/7gyp1
Date: 2023/8/8
Skill:
Ref:
Runtime: 1990 ms, faster than 92.17%
Memory Usage: 42.74 MB, less than 32.53%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Node:
    def __init__(self, c):
        self.c = c
        self.next = defaultdict(Node)


class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root, res = Node("/"), []
        for path in paths:
            cur_node = root
            for c in path:
                if c not in cur_node.next:
                    cur_node.next[c] = Node(c)
                cur_node = cur_node.next[c]

        string2key, key_num, node2key, key2count = defaultdict(int), 1, defaultdict(int), defaultdict(int)

        def get_id(node):
            nonlocal key_num
            s = ""
            keys = sorted(list(node.next.keys()))
            if len(keys) > 0:
                for n in keys:
                    s += get_id(node.next[n]) + "#" + n + "#"
            if s not in string2key:
                string2key[s] = str(key_num)
                key_num += 1
                key2count[string2key[s]] = 1
            else:
                key2count[string2key[s]] += 1
            node2key[node] = string2key[s]
            return string2key[s]

        get_id(root)

        def dfs(node, cur_path):
            nonlocal res
            key = node2key[node]
            if len(node.next) == 0:
                cur_path.append(node.c)
                res.append(cur_path.copy())
                return
            if node.c != "/":
                if key2count[key] > 1:
                    return
                cur_path.append(node.c)
                res.append(cur_path.copy())
            for n in node.next.keys():
                dfs(node.next[n], cur_path.copy())

        dfs(root, [])
        return res


if __name__ == "__main__":
    s = Solution()
    paths = [["e"], ["e", "e"], ["c"], ["c", "a"], ["c", "a", "e"], ["c", "a", "e", "b"], ["d"], ["d", "d"],
             ["d", "d", "c"], ["d", "d", "e"], ["d", "d", "e", "e"], ["d", "b"], ["d", "b", "a"], ["d", "b", "a", "e"],
             ["d", "b", "a", "e", "c"], ["d", "b", "a", "e", "e"], ["d", "b", "b"], ["d", "b", "c"], ["a"], ["b"]]
    res = s.deleteDuplicateFolder(paths)
    print(res)
