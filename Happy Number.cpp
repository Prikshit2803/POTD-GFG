class Solution{
public:



int sumofsquares(int n){
    int sum=0;
    while(n){
        int digit = n%10;
        sum+=digit*digit;
        n=n/10;
    }
    
    return sum;
}

 bool isHappy(int N){
      set<int> st;
     while(1){
      N = sumofsquares(N);
     
     if(N==1)
     return true;
     
     
     if(st.find(N)!=st.end())
     return false;
     
     st.insert(N);
     }
     
   
 }
    int nextHappy(int N){
        
        N++;
        
        while(isHappy(N)!=true){
            N++;
        }
        
        return N;
    }
    
};
