"""
Source: https://rb.gy/xutt0
Date: 2023/7/4
Skill: BFS
Ref:
Runtime: 48 ms, faster than 46.82%
Memory Usage: 16.4 MB, less than 14.32%
Time complexity:
Space complexity:
Constraints:
    0 <= bank.length <= 10
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if endGene not in bank:
            return -1
        res, candidate_set, visited, gene = 0, set(), set(), ["A", "C", "G", "T"]
        candidate_set.add(startGene)
        visited.add(startGene)
        while len(candidate_set) > 0:
            res += 1
            next_candidate_set = set()
            for gene_string in candidate_set:
                for i in range(8):
                    cur_gene_string = gene_string
                    for g in gene:
                        cur_gene_string = list(cur_gene_string)
                        cur_gene_string[i] = g
                        cur_gene_string = "".join(cur_gene_string)
                        if cur_gene_string == endGene:
                            return res
                        if cur_gene_string in bank and cur_gene_string not in visited:
                            visited.add(cur_gene_string)
                            next_candidate_set.add(cur_gene_string)
            candidate_set = next_candidate_set
        return -1


if __name__ == "__main__":
    s = Solution()
