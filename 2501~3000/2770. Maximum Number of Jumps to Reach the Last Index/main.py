"""
Source: https://rb.gy/wwdvi
Date: 2023/7/23
Skill:
Ref:
Runtime: 1320 ms, faster than 6.35%
Memory Usage: 19.58 MB, less than 6.93%
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
    def maximumJumps(self, nums: List[int], target: int) -> int:
        neighbors, sz = defaultdict(list), len(nums)
        nums_with_index = []
        for i in range(sz):
            nums_with_index.append([nums[i], i])
        nums_with_index.sort(key=lambda x: x[0])
        for i in range(sz-1):
            for j in range(i+1, sz):
                if abs(nums_with_index[i][0] - nums_with_index[j][0]) <= target:
                    neighbors[min(nums_with_index[i][1], nums_with_index[j][1])].append(
                        max(nums_with_index[i][1], nums_with_index[j][1]))
                else:
                    break

        dp = [0 for _ in range(sz)]
        dp[0] = 1
        for i in range(sz - 1):
            if dp[i] > 0:
                for next_pos in neighbors[i]:
                    dp[next_pos] = max(dp[next_pos], dp[i] + 1)

        return dp[-1] - 1 if dp[-1] > 0 else -1


if __name__ == "__main__":
    s = Solution()
