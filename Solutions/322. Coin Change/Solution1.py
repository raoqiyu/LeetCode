class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        dp[i] = min(dp[i]-coins[0], dp[i]-coins[1], ...) + 1
        
        """
        
        self.amount_visited = dict()
        self.coins = coins
    
        return self.kernel(amount)
    
    def kernel(self, amount):
        if amount == 0:
            return 0
        if amount < 0:
            return -1
        if amount in self.amount_visited:
            return self.amount_visited[amount]
        min_cnt = float('inf')
        for coin in self.coins:
            tmp = self.kernel(amount - coin)
            if tmp >= 0 and tmp < min_cnt:
                min_cnt = tmp+1
                
        self.amount_visited[amount] = min_cnt if min_cnt < float('inf') else -1
        return self.amount_visited[amount]
            
