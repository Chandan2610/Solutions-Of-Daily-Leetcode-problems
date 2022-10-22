class Solution {
    public String minWindow(String s, String p) {
        
        HashMap<Character,Integer> map1 = new HashMap<>();
        HashMap<Character,Integer> map2 = new HashMap<>();
        int count1=p.length();
        int count2=0;
        
        for(int i=0;i<p.length();i++)
        {
            char ch=p.charAt(i);
            
            map1.put(ch,map1.getOrDefault(ch,0)+1);
        }
        
        int ans=Integer.MAX_VALUE;
        int ansi=0,ansj=0;
        
        int i=-1,j=-1;
        
        
        while(true)
        {
            boolean flag1=false;
            boolean flag2=false;
            
            while(i<s.length()-1)
            {
                flag1=true;
                i++;
                char ch=s.charAt(i);
                map2.put(ch,map2.getOrDefault(ch,0)+1);
                
                if(map2.get(ch)<=map1.getOrDefault(ch,0))
                {
                    count2++;
                }
                
                if(count1==count2)
                {
                    break;
                }
            }
            
            while(j<i)
            {
                flag2=true;
                j++;
                
                if(count1==count2 && i-j+1<ans)
                {
                    ans=i-j+1;
                    ansi=i;
                    ansj=j;
                }
                
                char ch=s.charAt(j);
                
                if(map2.get(ch)==1)
                {
                    map2.remove(ch);
                }
                else
                {
                    map2.put(ch,map2.get(ch)-1);
                }
                
                if(map2.getOrDefault(ch,0)<map1.getOrDefault(ch,0))
                {
                    count2--;
                }
                
                if(count2<count1)
                {
                    break;
                }
            }
            
            if(!flag1 && !flag2)
            {
                break;
            }
        }
        
        if(ans==Integer.MAX_VALUE)
        return "";
        
        return s.substring(ansj,ansi+1);
        
    }
}