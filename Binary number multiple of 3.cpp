class Solution{
public:	
	// use 	DFA(finite automata of a binary number divisible by 3)
	int isDivisible(string s){
	   
	   int cnt=0; 
	   
	    for(int i=s.length()-1;i>=0;i--){
	        if(s[i]=='1'){
	            
	            if(cnt==0){
	             cnt=1;
	             continue;
	            }
	            
	            
	            if(cnt==1){
	            cnt=0;
	            continue;
	            }
	            
	            if(cnt==2){
	            cnt=2;
	            continue;
	            }
	        }
	        
	        else if(s[i]=='0'){
	            
	            if(cnt==0){
	            cnt=0;
	            continue;
	            }
	            
	            if(cnt==1){
	            cnt=2;
	            continue;
	            }
	            
	            if(cnt==2){
	            cnt=1;
	            continue;
	            }
	        }
	        
	    }
	    
	    if(cnt==0)
	    return 1;
	    
	    else
	    return 0;
	}

};
