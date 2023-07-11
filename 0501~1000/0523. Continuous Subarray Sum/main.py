"""
Source: https://rb.gy/prtvy
Date: 2023/7/11
Skill: Prefix sum
Ref:
Runtime: 1050 ms, faster than 12.6%
Memory Usage: 34.2 MB, less than 94.55%
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
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        presum, mydict, cur_sum, sz = [0 for i in range(len(nums))], defaultdict(int), 0, len(nums)
        mydict[0] = 1
        for i in range(sz):
            cur_sum += nums[i]
            presum[i] = cur_sum
            mydict[cur_sum % k] += 1
            if mydict[cur_sum % k] > 1:
                if mydict[cur_sum % k] == 2 and nums[i] % k == 0:
                    continue
                else:
                    return True
        return False


if __name__ == "__main__":
    s = Solution()
