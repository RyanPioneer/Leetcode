"""
Source: https://leetcode.com/problems/merge-strings-alternately/
Date: 2023/2/18
Skill:
Runtime: 28 ms, faster than 88.99%
Memory Usage: 13.9 MB, less than 12.75%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i, len1, len2, res = 0, len(word1), len(word2), ""
        for i in range(min(len1, len2)):
            res += word1[i]
            res += word2[i]

        res += word1[i+1:]
        res += word2[i+1:]
        return res


if __name__ == "__main__":
    s = Solution