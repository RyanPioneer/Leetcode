"""
Source: https://rb.gy/89jvq
Date: 2023/8/5
Skill:
Runtime: 1171 ms, faster than 98.10%
Memory Usage: 48.02 MB, less than 7.60%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 2 * 10^5
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        res, pos, neg = [0 for _ in range(len(nums))], 0, 1
        for num in nums:
            if num > 0:
                res[pos] = num
                pos += 2
            else:
                res[neg] = num
                neg += 2

        return res


if __name__ == "__main__":
    s = Solution()
