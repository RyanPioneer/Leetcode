"""
Source: https://leetcode.com/problems/lfu-cache/description/
Date: 2023/1/29
Skill:
Runtime: 894 ms, faster than 73.30%
Memory Usage: 77.3 MB, less than 94.82%
Time complexity:
Space complexity:
Constraints:
    0 <= capacity <= 10^4
    0 <= key <= 10^5
    0 <= value <= 10^9
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

class Node:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.freq = 1
        self.next = None
        self.prev = None


class LFUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.size = 0
        self.key2node = defaultdict()
        self.freq2node = defaultdict(list)
        self.min_freq = 1

    def get(self, key: int) -> int:
        if key not in self.key2node: return -1
        cur = self.key2node[key]
        cur.freq += 1
        cur.prev.next = cur.next
        cur.next.prev = cur.prev
        if self.min_freq == cur.freq-1 and self.freq2node[cur.freq-1][0].next == self.freq2node[cur.freq-1][1]:
            self.min_freq += 1
        if cur.freq not in self.freq2node:
            dummy_head, dummy_tail = Node(-1, -1), Node(-2, -2)
            dummy_head.next = dummy_tail
            dummy_tail.prev = dummy_head
            self.freq2node[cur.freq] = [dummy_head, dummy_tail]
        cur.next = self.freq2node[cur.freq][0].next
        cur.prev = self.freq2node[cur.freq][0]
        self.freq2node[cur.freq][0].next.prev = cur
        self.freq2node[cur.freq][0].next = cur
        return cur.val


    def put(self, key: int, value: int) -> None:
        if self.cap == 0: return
        if self.get(key) != -1:
            self.key2node[key].val = value
        else:
            if self.size == self.cap:
                self.size -= 1
                target = self.freq2node[self.min_freq][1].prev
                self.freq2node[self.min_freq][1].prev.prev.next = self.freq2node[self.min_freq][1]
                self.freq2node[self.min_freq][1].prev = self.freq2node[self.min_freq][1].prev.prev
                del self.key2node[target.key]
            self.min_freq = 1
            if 1 not in self.freq2node:
                dummy_head, dummy_tail = Node(-1, -1), Node(-2, -2)
                dummy_head.next = dummy_tail
                dummy_tail.prev = dummy_head
                self.freq2node[1] = [dummy_head, dummy_tail]
            cur = Node(key, value)
            self.key2node[key] = cur
            cur.next = self.freq2node[cur.freq][0].next
            cur.prev = self.freq2node[cur.freq][0]
            self.freq2node[cur.freq][0].next.prev = cur
            self.freq2node[cur.freq][0].next = cur
            self.size += 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)