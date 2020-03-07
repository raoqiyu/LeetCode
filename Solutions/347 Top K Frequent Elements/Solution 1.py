class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        self.heap = []
        self.heap_size = 0
        self.capacity = k
        num2cnts = {}
        for num in nums:
            if num in num2cnts:
                num2cnts[num] += 1
            else:
                num2cnts[num] = 1
        
        num2cnts_list = list(num2cnts.items())
        n_nums = len(num2cnts_list)
        for i in range(self.capacity):
            self.heap.append(num2cnts_list[i])

        self.build_heap()
        
        for i in range(self.capacity, n_nums):
            self.insert_heap(num2cnts_list[i])
            
        topk = [0 for _ in range(k)]
        for i in range(k):
            topk[k-i-1] = self.heap[0][0]
            self.heap[0] = self.heap[self.capacity-1]
            self.capacity -= 1
            self.heapify(0)
        
        return topk
        
    def heapify(self, parent):
        last_parent = self.capacity//2
        while parent < last_parent:
            left_child = parent*2+1
            right_child = left_child + 1
            next_parent = parent
            if left_child < self.capacity and \
                    self.heap[left_child][1] < self.heap[next_parent][1]:
                next_parent = left_child
            if right_child < self.capacity and \
                    self.heap[right_child][1] < self.heap[next_parent][1]:
                next_parent = right_child
            
            if parent == next_parent:
                break
            self.heap[next_parent], self.heap[parent] = self.heap[parent], self.heap[next_parent]
            parent = next_parent

                    
            
    def build_heap(self):
        for i in range(self.capacity//2-1, -1, -1):
            self.heapify(i)

    def insert_heap(self, num_cnt):
        if num_cnt[1] < self.heap[0][1]:
            return
        self.heap[0] = num_cnt
            
        self.heapify(0)
