class Solution:
    def isValid(self, s: str) -> bool:
        
        openBrackets, hashTable = list(), {'(' : ')', '{' : '}', '[' : ']'}
        for char in s:
            if char in hashTable:
                openBrackets.append(char)
            else:
                if not openBrackets or hashTable[openBrackets.pop()] != char:
                    return False

        return not openBrackets
        
