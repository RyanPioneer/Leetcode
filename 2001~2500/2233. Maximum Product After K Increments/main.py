"""
Source: https://rb.gy/9d4bs
Date: 2023/7/26
Skill:
Ref:
Runtime: 1091 ms, faster than 95.28%
Memory Usage: 27.05 MB, less than 32.08%
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
    def maximumProduct(self, nums: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        nums.sort()
        nums.append(sys.maxsize // len(nums))
        cur_sum, idx, sz, res = nums[0], 1, len(nums), 1
        while idx < sz and nums[idx] * idx - cur_sum <= k:
            cur_sum += nums[idx]
            idx += 1
        for i in range(idx):
            k -= nums[idx - 1] - nums[i]
            nums[i] = nums[idx - 1]

        for i in range(idx):
            nums[i] += k // idx

        for i in range(k % idx):
            nums[i] += 1

        for i in range(sz - 1):
            res *= nums[i] % MOD  # * Note!
            res %= MOD  # * Note!

        return res % MOD


if __name__ == "__main__":
    s = Solution()
    nums, k = [9, 7, 8], 9
    res = s.maximumProduct(nums, k)
