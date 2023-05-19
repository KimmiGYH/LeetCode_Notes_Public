class Solution:
    def operate(self, preSymbol, preResult, tempResult, tempNum):
        if preSymbol == "+":
            result = preResult + tempResult if tempResult is not None else preResult + int("".join(tempNum))
        else:
            result = preResult - tempResult if tempResult is not None else preResult - int("".join(tempNum))
        return result

    def cal(self, s: str, index = 0):
        left = index
        result = 0
        tempNum = []
        preSymbol = "+"
        tempResult = None
        while left < len(s):
            if s[left] == "(":
                tempResult, left = self.cal(s, left + 1)
            elif s[left] == ")":
                result = self.operate(preSymbol, result, tempResult, tempNum)
                return result, left + 1
            elif s[left] in {"+", "-"}:
                result = self.operate(preSymbol, result, tempResult, tempNum)
                tempNum = []
                tempResult = None
                preSymbol = s[left]
                left += 1
            elif s[left] == " ":
                left += 1
            else:
                tempNum.append(s[left])
                left += 1
        result = self.operate(preSymbol, result, tempResult, tempNum)
        return result, left


    def calculate(self, s: str) -> int:
        return self.cal(s)[0]