"""
Source: https://rb.gy/eww2c
Date: 2023/8/8
Skill:
Ref:
Runtime: 472 ms, faster than 86.18%
Memory Usage: 24.19 MB, less than 17.89%
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
    def maxEqualFreq(self, nums: List[int]) -> int:
        min_freq, max_freq, num2freq, freq_num, sz, res = 1, 1, defaultdict(int), defaultdict(int), len(nums), 0
        num2freq[nums[0]], freq_num[1] = 1, 1
        for i in range(1, sz):
            if nums[i] not in num2freq:
                num2freq[nums[i]] = 1
                min_freq = 1
            else:
                num2freq[nums[i]] += 1
                freq_num[num2freq[nums[i]] - 1] -= 1
                if freq_num[min_freq] == 0:
                    min_freq += 1

            freq_num[num2freq[nums[i]]] += 1
            max_freq = max(max_freq, num2freq[nums[i]])
            if min_freq == max_freq - 1 and freq_num[max_freq] == 1:
                res = i
            elif min_freq == 1 and freq_num[max_freq] * max_freq == i:
                res = i
            elif max_freq == 1:
                res = i
            elif max_freq == min_freq == i + 1:
                res = i

        return res + 1


if __name__ == "__main__":
    s = Solution()
    nums = [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5]
    res = s.maxEqualFreq(nums)
