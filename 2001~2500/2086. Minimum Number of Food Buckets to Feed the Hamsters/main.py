"""
Source: https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/
Date: 2023/4/15
Skill:
Ref:
Runtime: 99 ms, faster than 59.40%
Memory Usage: 15.6 MB, less than 48.12%
Time complexity:
Space complexity:
Constraints:
    1 <= hamsters.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimumBuckets(self, hamsters: str) -> int:
        res, sz = 0, len(hamsters)
        hamsters = list(hamsters)
        if hamsters[0] == "H":
            if sz == 1 or hamsters[1] == "H":
                return -1
            else:
                hamsters[1] = "B"
                res += 1
        if hamsters[sz - 1] == "H":
            if hamsters[sz - 2] == "H":
                return -1
            elif hamsters[sz - 2] == "B":
                pass
            else:
                hamsters[sz - 2] = "B"
                res += 1
        for i in range(1, sz - 1):
            if hamsters[i] == "H":
                if hamsters[i - 1] == "B" or hamsters[i + 1] == "B":
                    continue
                elif hamsters[i + 1] == "H":
                    if hamsters[i - 1] == ".":
                        res += 1
                    else:
                        return -1
                else:
                    hamsters[i + 1] = "B"
                    res += 1

        return res


if __name__ == "__main__":
    s = Solution()
    hamsters = ".H.H."
    res = s.minimumBuckets(hamsters)
    print(res)
