"""
Source: https://rb.gy/lwkll
Date: 2023/8/15
Skill:
Ref:
Runtime: 338 ms, faster than 19.48%
Memory Usage: 19.11 MB, less than 6.07%
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
        from sortedcontainers import SortedList
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        sl, cnt = SortedList(set(hand)), Counter(hand)
        for _ in range(len(hand) // groupSize):
            if len(sl) < groupSize:
                return False
            pos, todeleted = 0, set()
            cnt[sl[pos]] -= 1
            if cnt[sl[pos]] == 0:
                todeleted.add(sl[pos])
            for _ in range(groupSize - 1):
                pos += 1
                if sl[pos] - sl[pos - 1] != 1:
                    return False
                cnt[sl[pos]] -= 1
                if cnt[sl[pos]] == 0:
                    todeleted.add(sl[pos])
            for num in todeleted:
                sl.remove(num)

        return True


if __name__ == "__main__":
    s = Solution()

