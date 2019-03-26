class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest_consecutive_sequence_length = 0
        current_length = -1
        
        nums_set = set(nums)
        
        for num in nums:
            if num-1 not in nums_set:
                current_num = num
                current_length = 1
            
                while current_num +1 in nums_set:
                    current_num += 1
                    current_length += 1

                longest_consecutive_sequence_length = max(
                        longest_consecutive_sequence_length,
                        current_length)

        return longest_consecutive_sequence_length
