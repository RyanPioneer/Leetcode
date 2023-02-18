"""
Source: https://leetcode.com/problems/find-and-replace-pattern/
Date: 2023/2/18
Skill:
Runtime: 28 ms, faster than 93.77%
Memory Usage: 13.8 MB, less than 66.53%
Time complexity:
Space complexity:
Constraints:
    1 <= pattern.length <= 20
    1 <= words.length <= 50
    words[i].length == pattern.length
    pattern and words[i] are lowercase English letters.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        res, pattern_dict, idx, new_pattern, sz = [], defaultdict(), 0, "", len(pattern)
        for i in range(sz):
            if pattern[i] not in pattern_dict:
                pattern_dict[pattern[i]] = chr(ord("a")+idx)
                idx += 1
            new_pattern += pattern_dict[pattern[i]]

        for word in words:
            local_dict, idx, flag = defaultdict(), 0, True
            for i in range(sz):
                if word[i] not in local_dict:
                    local_dict[word[i]] = chr(ord("a")+idx)
                    idx += 1
                if local_dict[word[i]] != new_pattern[i]:
                    flag = False
                    break
            if flag:
                res.append(word)

        return res


if __name__ == "__main__":
    s = Solution