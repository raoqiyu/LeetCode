class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        Dynamic Programming
        
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        ret = [ set([]) for i in range(target+1)]
        ret[0] = ([()])
        for candidate in candidates:
            for temp_target in range(target, candidate-1,-1):
                for combation in ret[temp_target-candidate]:
                    ret[temp_target].add(combation + (candidate,))
                    
        return list(ret[target])
