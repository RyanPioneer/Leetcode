"""
Source: https://leetcode.com/problems/word-break/
Date: 2023/3/17
Skill:
Runtime: 54 ms, faster than 15.55%
Memory Usage: 17.2 MB, less than 5.37%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 300
    The same word in the dictionary may be reused multiple times in the segmentation.
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        class TrieNode:
            def __init__(self):
                self.next = [None for _ in range(26)]
                self.is_end = False

        def char2idx(c):
            return ord(c) - ord("a")

        root, sz, memo = TrieNode(), len(s), [0 for _ in range(len(s))]
        for word in wordDict:
            node = root
            for char in word:
                idx = char2idx(char)
                if not node.next[idx]:
                    node.next[idx] = TrieNode()
                node = node.next[idx]
            node.is_end = True

        def dfs(pos):
            if pos == sz:
                return True
            if memo[pos]:
                return False
            node = root
            for i in range(pos, sz):
                idx = char2idx(s[i])
                if not node.next[idx]:
                    break
                node = node.next[idx]
                if node.is_end and dfs(i + 1):
                    return True
            memo[pos] = 1
            return False

        return dfs(0)


if __name__ == "__main__":
    string = "leetcode"
    wordDict = ["leet", "code"]
    s = Solution()
    res = s.wordBreak(string, wordDict)
