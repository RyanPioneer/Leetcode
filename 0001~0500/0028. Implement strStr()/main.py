"""
Source: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
Date: 2023/3/4
Skill: KMP
Ref: shorturl.at/fhyDX
Runtime: 32 ms, faster than 66.84%
Memory Usage: 13.8 MB, less than 54.39%
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
    def strStr(self, haystack: str, needle: str) -> int:
        suf, dp = [0 for _ in range(len(needle))], [0 for _ in range(len(haystack))]

        def preprocess():
            for i in range(1, len(needle)):
                j = suf[i - 1]
                while j > 0 and needle[i] != needle[j]:
                    j = suf[j - 1]

                suf[i] = j + (needle[i] == needle[j])

        preprocess()
        if needle[0] == haystack[0]:
            dp[0] = 1
        if len(needle) == 1 and dp[0]:
            return 0
        for i in range(1, len(haystack)):
            j = dp[i - 1]
            while j > 0 and haystack[i] != needle[j]:
                j = suf[j - 1]
            dp[i] = j + (haystack[i] == needle[j])
            if dp[i] == len(needle):
                return i - len(needle) + 1

        return -1


if __name__ == "__main__":
    s = Solution()
