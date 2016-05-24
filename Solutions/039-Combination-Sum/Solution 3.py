class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret = []
        # Depth-First-Search
        def dfs(candidates, target, sol):
            for i in range(len(candidates)):
                tmp = target - candidates[i]
                if  tmp < 0:
                    break
                elif tmp == 0:
                    ret.append(sol+[candidates[i]])
                else:
                    dfs(candidates[i:], target-candidates[i], sol+[candidates[i]])
            

        candidates.sort()
        dfs(candidates, target, [])
        return ret
