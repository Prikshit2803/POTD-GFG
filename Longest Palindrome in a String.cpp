 string longestPalin (string S) {
        
        string ans="";
   int start=0;
   int len=1;// 1 as atleast one length of palindrome 
   int l,h;
   //h-l+1 gives string length and start tells start index and  len tells length of longest palindrome so far
   
   for(int i=1;i<S.length();i++){
       
       //for even palindrome
       l=i-1;
       h=i;
       
       while(l>=0 && h<S.length() && S[l]==S[h]){
           if((h-l+1)>len){
               start=l;
               len=h-l+1;
           }
           
           l--;
           h++;
       }
       
       //odd palindrome
       
       l=i-1;
       h=i+1;
       
       while(l>=0 && h<S.length() && S[l]==S[h]){
           if((h-l+1)>len){
               start=l;
               len=h-l+1;
           }
           
           l--;
           h++;
       }
   }
   
   
   
//   for(int i=0;i<=len;i++){
//       ans=ans+S[start++];
//   }

ans=S.substr(start,len); // function gives substring from start that is of length l
   
   return ans;
    }
};

//similar approach
 int n=s.size();
        int len=0,i,l,r;
        string ans="";
        for(i=0;i<n;i++)
        {
            //odd length substring
            l=i;
            r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                    if(r-l+1>len)
                    {
                        len=r-l+1;
                        ans=s.substr(l,len);
                    }
                --l;
                ++r;
            }
            //even length substring
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                    if(r-l+1>len)
                    {
                        len=r-l+1;
                        ans=s.substr(l,len);
                    }
                --l;
                ++r;
            }
        }
        return ans;
