"""
Source: https://rb.gy/as64p
Date: 2023/7/12
Skill:
Ref:
Runtime: 620 ms, faster than 9%
Memory Usage: 28.6 MB, less than 96%
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
    def countSubarrays(self, nums: List[int], k: int) -> int:
        for i in range(len(nums)):
            if nums[i] > k:
                nums[i] = 1
            elif nums[i] == k:
                nums[i] = 0
            else:
                nums[i] = -1
        res, cur_sum, odd_sum, even_sum = 0, 0, defaultdict(int), defaultdict(int)
        even_sum[0] = 1
        for i in range(len(nums)):
            cur_sum += nums[i]
            if i % 2 == 0: # odd
                res += odd_sum[cur_sum - 1]
                res += even_sum[cur_sum]
                odd_sum[cur_sum] += 1
            else:
                res += odd_sum[cur_sum]
                res += even_sum[cur_sum - 1]
                even_sum[cur_sum] += 1
        return res


if __name__ == "__main__":
    s = Solution()
