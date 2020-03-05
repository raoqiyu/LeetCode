class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        MAX = 0x7FFFFFFF
        
        ret_sum = 0
        carry = 0
        for i in range(32):
            ai = (a>>i) & 0x1
            bi = (b>>i) & 0x1
            s = ai ^ bi ^ carry
            ret_sum = (ret_sum | (s<<i))
            carry = (ai&bi) | ((ai ^ bi) & carry)            
        
        # 如果一个负数n，它的无符号32位补码是m，那么m=~(n ^ mask), n=~(m ^ mask)
        return ret_sum if ret_sum < MAX else ~(ret_sum^mask)
