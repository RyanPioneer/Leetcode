"""
Source: https://leetcode.com/problems/split-two-strings-to-make-palindrome/
Date: 2023/4/18
Skill:
Ref:
Runtime: 111 ms, faster than 35.71%
Memory Usage: 15 MB, less than 96.43%
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
    def checkPalindromeFormation(self, a: str, b: str) -> bool:

        def check_palindrome(s):
            start, end = 0, len(s) - 1
            while start < end:
                if s[start] != s[end]:
                    return False
                start += 1
                end -= 1
            return True

        def check(x, y):
            start, end = 0, len(x) - 1
            while start < end and x[start] == y[end]:
                start += 1
                end -= 1
            if start >= end:
                return True
            else:
                return check_palindrome(x[start: end + 1]) or check_palindrome(y[start: end + 1])

        return check(a, b) or check(b, a)


if __name__ == "__main__":
    s = Solution()
