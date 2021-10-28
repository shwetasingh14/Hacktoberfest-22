class Solution(object):
    
    def longestPalindrome(self, s):
        start=0
        end=len(s)
        res=""
        result=""
        for i in range(end):
            res1=self.fun(s,i,i+1)
            res2=self.fun(s,i,i)
            if len(res1)>len(res2) and len(result)<len(res1):
                result=res1
            elif len(res1)<len(res2) and len(result)<len(res2):
                result=res2
            
        return result       
        
    def fun(self,s,i,j):
        while i>=0 and j<len(s):
            if s[i]==s[j]:
                i-=1
                j+=1
            else:
                return s[i+1:j]
        
        return s[i+1:j]
