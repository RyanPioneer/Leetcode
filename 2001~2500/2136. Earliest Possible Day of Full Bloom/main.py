"""
Source: https://rb.gy/apqfn
Date: 2023/8/7
Skill:
Ref:
Runtime: 1490 ms, faster than 78.92%
Memory Usage: 35.62 MB, less than 42.70%
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
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        time, sz = [[plantTime[i], growTime[i]] for i in range(len(plantTime))], len(plantTime)
        time.sort(key=lambda x: x[1], reverse=True)
        cur_time, res = 0, 0
        for i in range(sz):
            cur_time += time[i][0]
            res = max(res, cur_time + time[i][1])
        return res


if __name__ == "__main__":
    s = Solution()
