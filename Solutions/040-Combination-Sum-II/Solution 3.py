class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        Backtracking
        
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.ret = []
        candidates.sort()
        self.backtracking(candidates, target, [])
        return self.ret
        
        
    def backtracking(self, candidates, target, comb):
        
        # bound 
        if not candidates or candidates[0] > target:
            return
        
        i, lens = 0,  len(candidates)
        while i < lens:
            if candidates[i] == target:
                self.ret.append(comb + [candidates[i]])
            elif candidates[i] > target:
                i = i+1
                continue
            else:
                # branch
                # Each number in C may only be used once in the combination.
                # so next time , begin at i+1
                self.backtracking(candidates[i+1:], target-candidates[i], comb+[candidates[i]])
            
            # To avoid [1,7],[1,7] cases
            # if we have two 1( [1,1,....,7])
            # so, without the while loop, it will produce two duplicate solutions([1,7],[1,7])
            # we need to skip all values same as current value
            while i < lens-1 and candidates[i] == candidates[i+1]:
                i += 1
                
            i += 1
        return 
        
