// My approach TC: O(Nk) and SC: o(n)
class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int> dq;
        int ans;
        
        for(int i=1;i<=N;i++){
            dq.push_back(i);
        }
        
        while(!dq.empty()){
            for(int i=0;i<K;i++){
                if(dq.empty())
                break;
                ans=dq.front();
                dq.pop_front();
            }
            
             for(int i=0;i<K;i++){
                 if(dq.empty())
                break;
                ans=dq.back();
                dq.pop_back();
            }
        }
        
        return ans;
    }
};


// TC : O(N) and SC O(1)
// Video link : https://www.youtube.com/watch?v=MCiQQP7y1J

int distributeTicket(int N, int K) {
        // code here
        int i=1,j=N,ans;
        bool a=false;
        while(i<=j){
            if(!a){
                i+=K;
                ans=j;
            }
            else{
                j-=K;
                ans=i;
            }
            a=!a;
        }
        return ans;
    }
// a is so that alternate ticket giving  is possible


// Another soln  TC : O(1)
 int distributeTicket(int N, int K) {
        // code here
        int step = N/K;
        int left = step/2;
        int right = left;
        if(step%2!=0)left++;  // if odd steps then left has more steps as it starts first
        int i = K*left;
        int j = N+1-K*right; // N+1 is used to get at last person that gets ticket
        if(step%2!=0){
            if(N%K==0)return i;
            return i+1; // this because it means that less than k elements left and we are moving from right to left hence element right after i will be last
        }
        if(N%K==0)return j;
        return j-1; // similar to return i+1
    }
