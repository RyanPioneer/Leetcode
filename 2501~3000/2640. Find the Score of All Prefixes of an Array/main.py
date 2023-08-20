"""
Source: https://rb.gy/dcqpw
Date: 2023/8/20
Skill:
Runtime: 428 ms, faster than 88.10%
Memory Usage: 39.09 MB, less than 57.47%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        res, sz, cur_max = [nums[0] * 2], len(nums), nums[0]
        for i in range(1, sz):
            cur_max = max(cur_max, nums[i])
            res.append(res[-1] + nums[i] + cur_max)
        return res


if __name__ == "__main__":
    s = Solution()
