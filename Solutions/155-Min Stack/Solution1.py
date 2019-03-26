class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        current_min = self.getMin()
        if current_min is None or current_min > x:
            current_min = x
        self.stack.append((x,current_min))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return None if not self.stack else self.stack[-1][0]

    def getMin(self) -> int:
        return None if not self.stack else self.stack[-1][-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
