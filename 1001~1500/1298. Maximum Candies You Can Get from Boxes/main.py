"""
Source: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
Date: 2023/4/21
Skill:
Ref:
Runtime: 786 ms, faster than 79.7%
Memory Usage: 27 MB, less than 91.86%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        mykeys, q, res, have_change = set(), deque(initialBoxes.copy()), 0, True
        while q and have_change:
            sz = len(q)
            have_change = False
            for _ in range(sz):
                cur_box = q.popleft()
                if not status[cur_box] and cur_box not in mykeys:
                    q.append(cur_box)
                else:
                    have_change = True
                    res += candies[cur_box]
                    for key in keys[cur_box]:
                        mykeys.add(key)
                    for box in containedBoxes[cur_box]:
                        q.append(box)

        return res


if __name__ == "__main__":
    s = Solution()
