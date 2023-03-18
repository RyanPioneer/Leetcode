"""
Source: https://leetcode.com/problems/random-pick-with-weight/
Date: 2023/3/18
Skill:
Runtime: 207 ms, faster than 85.60%
Memory Usage: 18.6 MB, less than 43.28%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left

class Solution:

    def __init__(self, w: List[int]):
        self.cummulative_probability_distribution = []
        weight = -1
        for num in w:
            weight += num
            self.cummulative_probability_distribution.append(weight)

    def pickIndex(self) -> int:
        picked_num = random.randint(0, self.cummulative_probability_distribution[-1])
        return bisect_left(self.cummulative_probability_distribution, picked_num)

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()


if __name__ == "__main__":
    s = Solution()
