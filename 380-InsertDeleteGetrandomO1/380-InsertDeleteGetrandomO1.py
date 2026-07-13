# Last updated: 13/07/2026, 22:20:32
class RandomizedSet:
    def __init__(self):
        self.randSet = list()
        self.map = dict()

    def insert(self, val: int) -> bool:
        if (val in self.map):
            return False
        self.map[val] = len(self.randSet)
        self.randSet.append(val)
        return True

    def remove(self, val: int) -> bool:
        if (val in self.map):
            self.randSet.remove(val)
            del self.map[val]
            return True
        return False

    def getRandom(self) -> int:
        from random import randint
        return self.randSet[randint(0 , len(self.randSet) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()