"""
Source: https://rb.gy/ezdma
Date: 2023/7/24
Skill:
Ref:
Runtime: 118 ms, faster than 50.00%
Memory Usage: 16.48 MB, less than 100.00%
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
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        res = []
        for word in words:
            word = word.split(separator)
            for i in word:
                if i != "":
                    res.append(i)
        return res


if __name__ == "__main__":
    s = Solution()
