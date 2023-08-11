"""
Source: https://rb.gy/hfkgv
Date: 2023/8/11
Skill:
Ref:
Runtime: 63 ms, faster than 80.39%
Memory Usage: 17.68 MB, less than 46.97%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 12
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        sz, res = len(s), []

        def back_tracking(idx, cur_string):
            if idx == sz:
                res.append(cur_string)
                return
            if s[idx].isdigit():
                back_tracking(idx + 1, cur_string)
            else:
                back_tracking(idx + 1, cur_string[:idx] + cur_string[idx].upper() + cur_string[idx + 1:])
                back_tracking(idx + 1, cur_string[:idx] + cur_string[idx].lower() + cur_string[idx + 1:])

        back_tracking(0, s)
        return res


if __name__ == "__main__":
    s = Solution()
