"""
Source: https://rb.gy/gmemb
Date: 2023/7/10
Skill:
Ref:
Runtime: 278 ms, faster than 93.20%
Memory Usage: 17 MB, less than 100%
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
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        left, right, res, cur_sum, sz = 0, 0, 0, 0, len(nums)
        if goal == 0:
            while right < sz:
                while left < sz and nums[left] == 1:
                    left += 1
                if left == sz:
                    break
                right = left + 1
                while right < sz and nums[right] == 0:
                    right += 1
                res += (right - left) * (right - left + 1) // 2
                left = right
        else:
            right = 1
            cur_sum += nums[0]
            while right < sz:
                while right < sz and cur_sum < goal:
                    cur_sum += nums[right]
                    right += 1
                if cur_sum < goal:
                    break
                right_num, left_num = 1, 1
                while right < sz and nums[right] == 0:
                    right_num += 1
                    right += 1
                while nums[left] == 0:
                    left_num += 1
                    left += 1
                res += left_num * right_num
                cur_sum -= nums[left]
                left += 1

        return res


if __name__ == "__main__":
    s = Solution()
