"""
Source: https://leetcode.com/problems/accounts-merge/
Date: 2023/1/25
Skill: Disjoint Set Union (DSU)
Runtime: 191 ms, faster than 94.72%
Memory Usage: 17.7 MB, less than 88.79%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class UF:
    def __init__(self, sz):
        self.parents = [i for i in range(sz)]

    def find(self, child):
        if self.parents[child] != child:
            self.parents[child] = self.find(self.parents[child])
        return self.parents[child]

    def union(self, child, parent):
        self.parents[self.find(child)] = self.find(parent)


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uf = UF(len(accounts))
        ownership = {}

        for i, (_, *emails) in enumerate(accounts):
            for email in emails:
                if email in ownership:
                    uf.union(i, ownership[email])
                else:
                    ownership[email] = i

        ans = defaultdict(list)
        for email, owner in ownership.items():
            ans[uf.find(owner)].append(email)

        return [[accounts[i][0]] + sorted(emails) for i, emails in ans.items()]