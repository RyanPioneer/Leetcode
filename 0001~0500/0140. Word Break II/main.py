"""
Source: https://rb.gy/0yjpw
Date: 2023/8/9
Skill:
Ref:
Runtime: 39 ms, faster than 78.37%
Memory Usage: 16.46 MB, less than 21.76%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 20
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set, sz, res = set(wordDict), len(s), []
        memo, visited = [[] for _ in range(sz)], [False for _ in range(sz)]

        def dfs(idx, cur_string):
            if idx == sz:
                res.append(cur_string)
                return []
            next_string_list = []
            if visited[idx]:
                for next in memo[idx]:
                    if cur_string != "":
                        res.append(cur_string + " " + next)
                    else:
                        res.append(next)
                return memo[idx]
            for i in range(idx + 1, sz + 1):
                if s[idx: i] in word_set:
                    if cur_string != "":
                        next_string = cur_string + " " + s[idx: i]
                    else:
                        next_string = s[idx: i]
                    next_string_sublist = dfs(i, next_string)
                    if len(next_string_sublist) != 0:
                        for string in next_string_sublist:
                            next_string_list.append(s[idx: i] + " " + string)
                    elif i == sz:
                        next_string_list.append(s[idx: i])
            memo[idx] = next_string_list
            visited[idx] = True
            return next_string_list

        dfs(0, "")
        return res


if __name__ == "__main__":
    s = Solution()
    string, wordDict = "aaaaaaa", ["aaaa", "aa", "a"]
    res = s.wordBreak(string, wordDict)
    print(res)
