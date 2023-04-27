"""
Source: https://leetcode.com/problems/add-digits/
Date: 2023/4/26
Skill:
Ref: https://leetcode.com/problems/add-digits/solutions/1754049/easy-o-1-explanation-with-example/
Runtime: 30 ms, faster than 84.34%
Memory Usage: 13.7 MB, less than 90.82%
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
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        return num % 9 if num % 9 != 0 else 9


if __name__ == "__main__":
    s = Solution()
