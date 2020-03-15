class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        if amount < 0:
            return -1
        self.coins = sorted(coin for coin in coins if coin <= amount)
        if not self.coins:
            return -1
        self.n = len(self.coins)
        self.min_cnt = amount + 1
        
        self.kernel(amount, self.n-1, 0)
        
        return self.min_cnt if self.min_cnt < amount + 1 else -1
        
    def kernel(self, amount, coin_idx, coin_used_cnt):
        coin = self.coins[coin_idx]
        
        coin_cnt, amount_left = amount // coin, amount%coin
        
        if amount_left == 0:
            self.min_cnt = min(self.min_cnt, coin_cnt+coin_used_cnt)
            return
        if coin_idx == 0 or coin_cnt+coin_used_cnt+1 >= self.min_cnt:
            return
        for n in range(coin_cnt, -1, -1):
            self.kernel(amount-coin*n, coin_idx-1, coin_used_cnt+n)
        
