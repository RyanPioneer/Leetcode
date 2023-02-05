"""
Source: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
Date: 2023/2/4
Skill:
Runtime: 52 ms, faster than 89.52%
Memory Usage: 13.9 MB, less than 26.74%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 100
    words[i] consists of lowercase English letters.
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        index, sz, res = 1, len(words), [words[0]]
        while index < sz:
            word1, word2 = sorted(list(words[index-1])), sorted(list(words[index]))
            if word1 != word2:
                res.append(words[index])
            index += 1

        return res

if __name__ == "__main__":
    s = Solution
    words = ["abba","baba","bbaa","cd","cd"]
    res = s.removeAnagrams(s, words)