long long findMinDiff(vector<long long> a, long long n, long long m){
              
              sort(a.begin(),a.end());
              
              int ans=INT_MAX;
              
              for(int i=0;i<=n-m;i++){
                 
                  int ap=a[i+m-1]-a[i];
                  
                  ans=min(ap,ans);
              }
    
        return ans;
    }   
