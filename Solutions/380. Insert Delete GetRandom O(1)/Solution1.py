import random
from collections import defaultdict
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.val2idx = defaultdict(int)
        self.vals = []
        
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.val2idx.keys():
            return False
        
        self.vals.append(val)
        self.val2idx[val] = len(self.vals)-1
        return True
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.val2idx:
            return False
        
        idx = self.val2idx.pop(val)
        if idx == len(self.vals)-1:
            self.vals.pop()
        else:
            tmp_val = self.vals.pop()
            self.vals[idx] = tmp_val
            self.val2idx[tmp_val] = idx
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return random.choice(self.vals)
