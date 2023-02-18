"""
Source: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
Date: 2023/2/17
Skill:
Runtime: 835 ms, faster than 71.91%
Memory Usage: 31.2 MB, less than 47.87%
Time complexity:
Space complexity:
Constraints:
    1 <= nums[i] <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        my_dict, res, cur_sum, sz = defaultdict(int), 0, 0, len(nums)
        for i in range(k):
            my_dict[nums[i]] += 1
            cur_sum += nums[i]

        if len(my_dict) == k:
            res = cur_sum

        for i in range(k, sz):
            cur_sum += nums[i]
            cur_sum -= nums[i-k]
            my_dict[nums[i]] += 1
            my_dict[nums[i-k]] -= 1
            if my_dict[nums[i-k]] == 0:
                del my_dict[nums[i-k]]
            if len(my_dict) == k:
                res = max(res, cur_sum)

        return res


if __name__ == "__main__":
    s = Solution