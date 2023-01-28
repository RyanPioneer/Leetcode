"""
Source: https://leetcode.com/problems/lru-cache/
Date: 2023/1/28
Skill:
Runtime: 841 ms, faster than 81.84%
Memory Usage: 75.8 MB, less than 49.21%
Time complexity:
Space complexity:
Constraints:
    1 <= capacity <= 3000
    0 <= key <= 10^4
    0 <= value <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Node:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.next = None
        self.prev = None

def connect(node1, node2):
    node1.next = node2
    node2.prev = node1

def delete(node):
    node.next.prev = node.prev
    node.prev.next = node.next
    return node

def insert(node1, node2):
    node1.next = node2
    node1.prev = node2.prev
    node2.prev.next = node1
    node2.prev = node1

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.size = 0
        self.dummy_head = Node(-1, -1)
        self.dummy_tail = Node(-2, -2)
        connect(self.dummy_head, self.dummy_tail)
        self.key2node = {}

    def get(self, key: int) -> int:
        if key not in self.key2node: return -1
        cur = delete(self.key2node[key])
        insert(cur, self.dummy_tail)
        return cur.val

    def put(self, key: int, value: int) -> None:
        if key not in self.key2node:
            if self.size == self.cap:
                del self.key2node[self.dummy_head.next.key]
                delete(self.dummy_head.next)
                self.size -= 1
            cur = Node(key, value)
            self.key2node[key] = cur
            insert(cur, self.dummy_tail)
            self.size += 1
        else:
            cur = delete(self.key2node[key])
            cur.val = value
            insert(cur, self.dummy_tail)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)