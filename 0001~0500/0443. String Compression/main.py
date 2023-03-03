"""
Source: https://leetcode.com/problems/string-compression/
Date: 2023/3/3
Skill:
Ref:
Runtime: 60 ms, faster than 73.60%
Memory Usage: 14 MB, less than 65.14%
Time complexity:
Space complexity:
Constraints:
    1 <= chars.length <= 2000
    chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution(object):

    def compress(self, chars):
        anchor, write, sz = 0, 0, len(chars)
        for pos, char in enumerate(chars):
            if pos == sz-1 or chars[pos] != chars[pos+1]:
                chars[write] = char
                write += 1
                if pos > anchor:
                    length = pos - anchor + 1
                    for num in str(length):
                        chars[write] = num
                        write += 1
                anchor = pos + 1

        return write


if __name__ == "__main__":
    s = Solution()
