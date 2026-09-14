# Last updated: 14/09/2026, 09:40:20
import random
from collections import defaultdict

class RandomizedCollection:
    def __init__(self):
        self.vals = []
        self.indices = defaultdict(set)

    def insert(self, val: int) -> bool:
        is_new = len(self.indices[val]) == 0
        
        self.vals.append(val)
        self.indices[val].add(len(self.vals) - 1)
        
        return is_new

    def remove(self, val: int) -> bool:
        if not self.indices[val]:
            return False
        
        remove_idx = self.indices[val].pop()
        
        last_val = self.vals[-1]
        last_idx = len(self.vals) - 1
        
        if remove_idx != last_idx:
            self.vals[remove_idx] = last_val
            self.indices[last_val].remove(last_idx)
            self.indices[last_val].add(remove_idx)
            
        self.vals.pop()
        
        return True

    def getRandom(self) -> int:
        return random.choice(self.vals)