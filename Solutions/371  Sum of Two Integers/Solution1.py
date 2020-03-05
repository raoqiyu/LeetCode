class Solution:
    def getSum(self, a: int, b: int) -> int:
        '''
        XOR
        1   =>  001 
        2   =>  010 
        1^2 =>  011 (2+1 = 3) 
        
        3  => 011 
        2  => 010 
        3^2=> 001  
        
        XOR cannot deal with the carry properly, so we should take care with carry
        AND can do this, because the carry is generated when both the bits are set
        3    =>  011 
        2    =>  010 
        3&2  =>  010
        
        3 ^2        =>  001 
        (3&2)<<1    =>  100 
        
        then XOR the two results and continue this until the carry becomes zero.
       
        '''

        # mask to get last 32 bits
        mask = 0xFFFFFFFF
        
        carry = 0
        while b&mask != 0:
            carry = (a&b)<<1
            a = (a^b)
            b = carry
            
        return a&mask if b>mask else a
                    
