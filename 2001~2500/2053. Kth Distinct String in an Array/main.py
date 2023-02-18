"""
Source: https://leetcode.com/problems/kth-distinct-string-in-an-array/
Date: 2023/2/18
Skill:
Ref:
Runtime: 75 ms, faster than 62.97%
Memory Usage: 14.1 MB, less than 44.5%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque, Counter
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        cnt, num = Counter(arr), 0
        for c in arr:
            if cnt[c] == 1:
                num += 1
                if num == k:
                    return c

        return ""


if __name__ == "__main__":
    s = Solution