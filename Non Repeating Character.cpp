char nonrepeatingCharacter(string S)
    {
       unordered_map<char,int> mp;
       
      
    
       for(int i=0;i<S.length();i++){
           mp[S[i]]++;
       }
       
       for(int i=0;i<S.length();i++){
          if(mp[S[i]]==1) 
          return S[i];
       
       
    }
    
    return '$';
    
    }
