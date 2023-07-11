 class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
        
          if(R==0)
      {
          return 1;
      }
       
        long long t=1e9+7;
        long long  ans= 1;
        long long temp=1;
        temp=power(N,R/2); //recusrion
        ans=(temp*temp)%t;
        
         if(R%2!=0){
              ans=(ans*N)%t;
          }
        
        
        return ans;
    }

};
