class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic={}
        for a in(strs):
            t=list(a)
            t.sort()
            t="".join(t)
            if(t in dic):
                dic[t].append(a)
            else:
                dic[t]=[a]
        ans=[]
        for a in dic:
            ans.append(dic[a])
        return(ans)
