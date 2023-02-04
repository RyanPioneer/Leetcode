"""
Source: https://leetcode.com/problems/palindrome-pairs/description/
Date: 2023/2/3
Skill:
Runtime: 3493 ms, faster than 64.4%
Memory Usage: 26.4 MB, less than 64.93%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 5000
    0 <= words[i].length <= 300
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        value2index, myset, res = {}, set(), []
        for i in range(len(words)):
            value2index[words[i]] = i

        words.sort(key=lambda x: len(x))

        for word in words:
            sz = len(word)
            for i in range(sz+1):
                if word[:i] == word[:i][::-1] and word[i:][::-1] in myset:
                    res.append([value2index[word[i:][::-1]], value2index[word]])
                if word[sz-i:] == word[sz-i:][::-1] and word[:sz-i][::-1] in myset:
                    res.append([value2index[word], value2index[word[:sz-i][::-1]]])

            myset.add(word)

        return res