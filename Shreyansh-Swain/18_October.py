'''The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one 
unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.'''



class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
    
        if n==1:
            return "1"
        x=self.countAndSay(n-1)
        s=""
        y=x[0]
        ct=1
        for i in range(1,len(x)):
            if x[i]==y:
                ct+=1
            else:
                s+=str(ct)
                s+=str(y)
                y=x[i]
                ct=1
        s+=str(ct)
        s+=str(y)
        return s   
