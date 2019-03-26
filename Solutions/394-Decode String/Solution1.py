class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return ''
        stack = []
        
        for c in s:
            if c != ']':
                stack.append(c)
            else:
                tmp = ''
                while stack[-1] != '[':
                    tmp = stack.pop() + tmp
                    
                # pop '['
                stack.pop()
                
                n_repeat = ''
                while stack and stack[-1].isdigit():
                    n_repeat = stack.pop() + n_repeat
                n_repeat = int(n_repeat)
                
                stack.append(tmp*n_repeat)
        return ''.join(stack)
                
        
