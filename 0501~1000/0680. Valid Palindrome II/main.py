"""
Source: https://leetcode.com/problems/valid-palindrome-ii/description/
Date: 2023/2/7
Skill: Two Pointers
Runtime: 152 ms, faster than 60.78%
Memory Usage: 14.5 MB, less than 85.91%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
    s consists of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def validPalindrome(self, s: str) -> bool:
        left, right = 0, len(s)-1

        def remove(head, tail):
            while head < tail:
                if s[head] != s[tail]:
                    return False
                head, tail = head+1, tail-1
            return True

        while left < right:
            if s[left] != s[right]:
                return remove(left+1, right) or remove(left, right-1)
            left, right = left+1, right-1

        return True


if __name__ == "__main__":
    s = Solution