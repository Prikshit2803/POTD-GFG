//Sliding window approach
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod=1,cnt=0;
        for(int i=0;i<n;i++){
            prod=1LL;
           int j=i;
           while(j<n){
               prod*=a[j];
               if(prod<k){
                   cnt++;
                    j++;
               }
                  
               
               if(prod>=k){
                   //prod=0;
               break;
               }
           }
        }
        
        return cnt;
    }
};
