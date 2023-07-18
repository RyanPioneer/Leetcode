"""
Source: https://rb.gy/bjryz
Date: 2023/7/18
Skill:
Ref:
Runtime: 701 ms, faster than 45.31%
Memory Usage: 25.76 MB, less than 66.02%
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
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_queue, min_queue, res, left, right, sz = deque([[nums[0], 0]]), deque([[nums[0], 0]]), 1, 0, 1, len(nums)
        while right < sz:
            res = max(res, right - left)
            if nums[right] - min_queue[0][0] > limit:
                while min_queue and nums[right] - min_queue[0][0] > limit:
                    left = min_queue[0][1] + 1
                    min_queue.popleft()
            elif max_queue[0][0] - nums[right] > limit:
                while max_queue and max_queue[0][0] - nums[right] > limit:
                    left = max_queue[0][1] + 1
                    max_queue.popleft()

            while max_queue and max_queue[-1][0] <= nums[right]:
                max_queue.pop()
            max_queue.append([nums[right], right])
            while min_queue and min_queue[-1][0] >= nums[right]:
                min_queue.pop()
            min_queue.append([nums[right], right])
            right += 1

        return max(res, right - left)


if __name__ == "__main__":
    s = Solution()
