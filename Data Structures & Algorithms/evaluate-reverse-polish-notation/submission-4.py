class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = []

        for token in tokens:
            if token == '+' or token == '-' or token == '*' or token == '/':
                b = s.pop()
                a = s.pop()

                if token == '+': s.append(a + b)
                elif token == '-': s.append(a - b)
                elif token == '*': s.append(a * b)
                else: s.append(int(a / b))
            else:
                s.append(int(token))
        return s[-1]