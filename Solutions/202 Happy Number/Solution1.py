class Solution:
    def isHappy(self, n: int) -> bool:
        if n <= 0:
            return False
        if n == 1:
            return True
            
        sum_visited,number_sum = set(), 0
        sum_visited.add(n)
        while True:
            number_sum += (n%10)**2
            n = n//10
            
            if n==0:
                if number_sum == 1:
                    return True
                elif number_sum in sum_visited:
                    return False
                else:
                    sum_visited.add(number_sum)
                    n,number_sum = number_sum, 0
        
