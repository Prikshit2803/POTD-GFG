//My TLE soln
string FirstNonRepeating(string A){
		    
		    vector<int> mp(26,0);
		    
		    string ans="";
		    
		    
		    
		    for(int i=0;i<A.length();i++){
		        int flag=0;
		        mp[A[i]-'a']++;
		        
		        for(int j=0;j<=i;j++){
		            if( mp[A[j]-'a']==1){
		            ans+=A[j];
		           flag=1;
		           break;
		            }
		        }
		        
		        if(flag==0)
		        ans+="#";
		        
		    }
		    
		    return ans;
		}

//Working soln
string FirstNonRepeating(string A){
		    
		    vector<int> mp(26,-1);
		    
		    string res="";
		    
		    
		    
		    for(int i=0;i<A.length();i++){
		        
		        if(mp[A[i]-'a']==-1)
		        mp[A[i]-'a']=i; //first occurence 
		        
		        else
		        mp[A[i]-'a']=-2; //it means repeat occurence and we dont count
		        
		        int ans=INT_MAX;
		        
		        for(int j=0;j<26;j++){
		            if(mp[j]>=0){
		                ans=min(ans,mp[j]); //minm index(i) of non-repeating character
		            }
		        }
		        
		        if(ans==INT_MAX){
		            res+="#";
		        }
		        
		        else
		        res+=A[ans];
		    }
		    
		    return res;
		}
