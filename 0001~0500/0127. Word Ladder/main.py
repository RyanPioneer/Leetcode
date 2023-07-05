"""
Source: https://rb.gy/1iglw
Date: 2023/7/4
Skill: BFS
Ref:
Runtime: 507 ms, faster than 35.11%
Memory Usage: 17.5 MB, less than 88.9%
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


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        alphabet, wordset = [], set(wordList)
        start = ord('a')
        for i in range(26):
            alphabet.append(chr(start + i))
        visitedWords, q, res = set(), deque([beginWord]), 1
        visitedWords.add(beginWord)
        while len(q):
            res += 1
            size = len(q)
            for i in range(size):
                word = q.popleft()
                for j in range(len(beginWord)):
                    for char in alphabet:
                        cur_word = word[:j] + char + word[j+1:]
                        if cur_word == endWord:
                            return res
                        if cur_word in wordset and cur_word not in visitedWords:
                            q.append(cur_word)
                            visitedWords.add(cur_word)
        return 0


if __name__ == "__main__":
    s = Solution()
