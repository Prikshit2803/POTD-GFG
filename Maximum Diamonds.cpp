//priority queue should be used
class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        
        //Brute force
    //   long long ans=0;
       
    //   while(K){
    //       sort(A,A+N);
          
    //       ans+=A[N-1];
    //       A[N-1]=A[N-1]/2;
          
    //       K--;
           
    //   }
    //   return ans;
    
    priority_queue<int> q;
    long long ans=0;
    long long cur;
    
    for(int i=0;i<N;i++)
    q.push(A[i]);
    

  

    
    while(K!=0){
        cur=q.top();
        q.pop();
        ans+=cur;
        q.push(cur/2);
        K--;
        
    }
    //ans=0;
    return ans;
    }
};
