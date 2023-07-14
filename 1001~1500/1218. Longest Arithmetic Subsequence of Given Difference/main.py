"""
Source: https://rb.gy/jiyf6
Date: 2023/7/14
Skill:
Ref:
Runtime: 523 ms, faster than 84.61%
Memory Usage: 29.82 MB, less than 99.28%
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
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        mydict = defaultdict(int)
        for num in arr:
            mydict[num] = mydict[num - difference] + 1
        return max(mydict.values())


if __name__ == "__main__":
    s = Solution()
