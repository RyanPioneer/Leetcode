"""
Source: https://rb.gy/lwkll
Date: 2023/8/15
Skill:
Ref:
Runtime: 177 ms, faster than 89.86%
Memory Usage: 18.3 MB, less than 15.45%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 1000
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        nums, cnt, time = sorted(list(set(hand))), Counter(hand), len(hand) // groupSize
        start, sz, idx = 0, len(nums), 0
        for _ in range(time):
            if sz - idx < groupSize:
                return False
            cnt[nums[idx]] -= 1
            for _ in range(groupSize - 1):
                idx += 1
                if cnt[nums[idx]] == 0 or nums[idx] - nums[idx - 1] != 1:
                    return False
                cnt[nums[idx]] -= 1
            while start < sz and cnt[nums[start]] == 0:
                start += 1
            idx = start

        return True


if __name__ == "__main__":
    s = Solution()

