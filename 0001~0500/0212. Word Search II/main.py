"""
Source: https://leetcode.com/problems/word-search-ii/
Date: 2023/3/16
Skill:
Runtime: 2206 ms, faster than 44.99%
Memory Usage: 20.3 MB, less than 5.1%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        class TrieNode:
            def __init__(self):
                self.next = [None for _ in range(26)]
                self.count = 0
                self.is_end = False

        def char2idx(c):
            return ord(c) - ord("a")

        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                if not node.next[char2idx(char)]:
                    node.next[char2idx(char)] = TrieNode()
                node = node.next[char2idx(char)]
                node.count += 1
            node.is_end = True

        m, n = len(board), len(board[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]
        directions = [0, 1, 0, -1, 0]
        res = set()

        def remove(word):
            node = root
            for char in word:
                node = node.next[char2idx(char)]
                node.count -= 1

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        def dfs(i, j, node, word):
            if not node.next[char2idx(board[i][j])] or \
                    not node.next[char2idx(board[i][j])].count:
                return
            node = node.next[char2idx(board[i][j])]
            word += board[i][j]
            if node.is_end:
                res.add(word)
                remove(word)
                node.is_end = False
            visited[i][j] = 1
            for k in range(len(directions) - 1):
                next_x, next_y = i + directions[k], j + directions[k+1]
                if not check_feasible(next_x, next_y) or visited[next_x][next_y]:
                    continue
                dfs(next_x, next_y, node, word)

            visited[i][j] = 0

        for i in range(m):
            for j in range(n):
                dfs(i, j, root, "")

        return list(res)


if __name__ == "__main__":
    s = Solution()
