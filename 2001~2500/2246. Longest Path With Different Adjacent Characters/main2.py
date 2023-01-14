"""
Source: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
Date: 2023/1/14
Skill:
Ref:
Runtime: 1692 ms, faster than 90.72%
Memory Usage: 32.4 MB, less than 99.59%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import deque


class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        sz, children_count, longest_chains, longest_path, deq = len(parent), [0 for _ in range(len(parent))], [[0, 0] for _ in range(len(parent))], 1, deque()
        for i in range(1, sz):
            children_count[parent[i]] += 1

        for i in range(1, sz):
            if children_count[i] == 0:
                deq.append(i)

        while deq:
            cur_node = deq.popleft()
            if s[cur_node] != s[parent[cur_node]]:
                if longest_chains[cur_node][0] + 1 > longest_chains[parent[cur_node]][0]:
                    longest_chains[parent[cur_node]][0], longest_chains[parent[cur_node]][1] =\
                        longest_chains[cur_node][0] + 1, longest_chains[parent[cur_node]][0]
                elif longest_chains[cur_node][0] + 1 > longest_chains[parent[cur_node]][1]:
                    longest_chains[parent[cur_node]][1] = longest_chains[cur_node][0] + 1

            children_count[parent[cur_node]] -= 1
            if children_count[parent[cur_node]] == 0:
                deq.append(parent[cur_node])
                longest_path = max(longest_path, longest_chains[parent[cur_node]][0]\
                                   + longest_chains[parent[cur_node]][1] + 1)

        return longest_path