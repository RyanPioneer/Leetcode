"""
Source: https://rb.gy/tm3mx
Date: 2023/8/5
Skill:
Ref:
Runtime: 234 ms, faster than 58.33%
Memory Usage: 23.45 MB, less than 32.35%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 2 * 10 ** 4
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        sz, k_sum, cur_sum = len(nums), [0 for _ in range(len(nums))], sum(nums[:k])
        k_sum[k - 1] = cur_sum
        for i in range(k, sz):
            cur_sum += nums[i] - nums[i - k]
            k_sum[i] = cur_sum
        dp1 = [i for i in range(sz)]
        for i in range(k, sz):
            if k_sum[dp1[i - 1]] < k_sum[i]:
                dp1[i] = i
            else:
                dp1[i] = dp1[i - 1]
        dp2 = [[0, 0] for _ in range(sz)]
        dp2[2 * k - 1] = [k - 1, 2 * k - 1]
        for i in range(2 * k, sz):
            if k_sum[i] + k_sum[dp1[i - k]] > k_sum[dp2[i - 1][0]] + k_sum[dp2[i - 1][1]]:
                dp2[i] = [dp1[i - k], i]
            else:
                dp2[i] = dp2[i - 1]

        dp3 = [[0, 0] for _ in range(sz)]
        dp3[3 * k - 1] = [k - 1, 2 * k - 1, 3 * k - 1]
        for i in range(3 * k, sz):
            if k_sum[i] + k_sum[dp2[i - k][0]] + k_sum[dp2[i - k][1]] > k_sum[dp3[i - 1][0]] + k_sum[dp3[i - 1][1]] + k_sum[dp3[i - 1][2]]:
                dp3[i] = [dp2[i - k][0], dp2[i - k][1], i]
            else:
                dp3[i] = dp3[i - 1]

        return [dp3[-1][0] - k + 1, dp3[-1][1] - k + 1, dp3[-1][2] - k + 1]


if __name__ == "__main__":
    s = Solution()
