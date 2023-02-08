"""
Source: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
Date: 2023/2/7
Skill:
Runtime: 70 ms, faster than 84.50%
Memory Usage: 13.8 MB, less than 94.78%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 100
    words[i] consists only of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if word == word[::-1]:
                return word
        return ""


if __name__ == "__main__":
    s = Solution