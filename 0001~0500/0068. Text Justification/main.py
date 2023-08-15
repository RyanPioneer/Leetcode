"""
Source: https://rb.gy/le1ci
Date: 2023/8/15
Skill:
Ref:
Runtime: 35 ms, faster than 93.01%
Memory Usage: 16.42 MB, less than 33.52%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res, sz, idx = [], len(words), 0
        while idx < sz:
            end, length, num = idx + 1, len(words[idx]), 1
            while end < sz and len(words[end]) + length + num <= maxWidth:
                length += len(words[end])
                num += 1
                end += 1
            line = ""
            if end == sz:
                space = 0
                while idx < sz - 1:
                    line += words[idx] + " "
                    space += len(words[idx]) + 1
                    idx += 1
                line += words[-1] + " " * (maxWidth - space - len(words[-1]))
                idx = sz
            elif num == 1:
                line += words[idx] + " " * (maxWidth - length)
                idx += 1
            else:
                extra_space = maxWidth - length
                while idx < end - 1:
                    cur_space = extra_space // (num - 1) if extra_space % (num - 1) == 0 else extra_space // (num - 1) + 1
                    extra_space -= cur_space
                    num -= 1
                    line += words[idx] + " " * cur_space
                    idx += 1
                line += words[idx]
                idx += 1

            res.append(line)

        return res


if __name__ == "__main__":
    s = Solution()

