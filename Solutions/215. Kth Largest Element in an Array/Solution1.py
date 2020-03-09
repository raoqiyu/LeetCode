class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        self.k, self.heap = k, []
        n = len(nums)
        
        for i in range(k):
            self.heap.append(nums[i])
        self.build_heap()
        for i in range(k, n):
            self.insert(nums[i])
        
        return self.heap[0]
            
        
        
    def build_heap(self):
        for i in range(self.k//2-1, -1, -1):
            self.heapify(i)
    
    def insert(self, num):
        if num < self.heap[0]:
            return

        self.heap[0] = num
        self.heapify(0)
        
    
    def heapify(self, parent):
        last_parent = self.k//2
        while parent < last_parent:
            left_child = parent*2+1
            right_child = left_child + 1
            next_parent = parent
            if left_child < self.k and self.heap[next_parent] > self.heap[left_child]:
                next_parent = left_child
            if right_child < self.k and self.heap[next_parent] > self.heap[right_child]:
                next_parent = right_child
                
            if parent == next_parent:
                break
            
            self.heap[parent], self.heap[next_parent] = self.heap[next_parent], self.heap[parent]
            parent = next_parent
        
