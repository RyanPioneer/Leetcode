"""
Source: https://leetcode.com/problems/largest-merge-of-two-strings/
Date: 2023/4/13
Skill:
Ref:
Runtime: 93 ms, faster than 68.18%
Memory Usage: 13.9 MB, less than 95.45%
Time complexity:
Space complexity:
Constraints:
    1 <= word1.length, word2.length <= 3000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        pos1, len1, pos2, len2, res = 0, len(word1), 0, len(word2), ""
        while pos1 < len1 and pos2 < len2:
            if word1[pos1: len1] >= word2[pos2: len2]:
                res += word1[pos1]
                pos1 += 1
            else:
                res += word2[pos2]
                pos2 += 1

        if pos1 < len1:
            res += word1[pos1: len1]
        else:
            res += word2[pos2: len2]

        return res


if __name__ == "__main__":
    s = Solution()
