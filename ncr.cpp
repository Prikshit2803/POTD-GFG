// nCr = n-1Cr + n-1Cr-1 || DP - Memoization/Tabulation || Easy & Understandable C++ Solution with explanation
// COMPLEXITY :

// TC : O(n*r)

// SC : O(n*r)

// APPROACH :

// nCr = n-1Cr + n-1Cr-1
// You must be aware of this combination formula. We will use this formula to calculate nCr. 
// MEMOIZATION :

// Create a 2D vector dp of size (n+1) by (r+1).
// Call the solve function
// Check the base cases, such that for 
//  for r>n => nCr=0
//  for r=0 => nCr=1
//  for r=1 => nCr = n 
// If the answer for n and r is already stored, retrieve the data from the dp table.
// Calculate the value of nCr using the combination formula and make the two required recursive calls.
// Return the answer while storing it in the dp table.
int mod=1e9+7;
    int solve(vector<vector<int>>&dp,int n,int r){
        if(r>n)return 0;
        if(r==0)return 1;
        if(r==1)return n;
        if(dp[n][r]!=-1)return dp[n][r];
        return dp[n][r]=(solve(dp,n-1,r-1)%mod + solve(dp,n-1,r)%mod)%mod;
    }
    int nCr(int n, int r){
        // code here
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        return solve(dp,n,r);
    }
 

// TABULATION :

// Create a 2D vector dp of size (n+1) by (r+1).
// Initialize the base cases, such that for r=0, for all value of n, nCr=1
// Now simply iterate from 0 to n in a nested loop from 1 to min(i,r) to avoid cases where j > i, because in nCr, we know that n >= r.
// Calculate the value of nCr using the previously stored values in the dp table.
// Return the answer.
int mod=1e9+7;
    int nCr(int n, int r){
        // code here
        int i,j;
        vector<vector<int>>dp(n+1,vector<int>(r+1,0));
        for(i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(i=0;i<=n;i++){
            for(j=1;j<=min(i,r);j++){
                dp[i][j]=(dp[i-1][j]%mod + dp[i-1][j-1]%mod)%mod;
            }
        }
        return dp[n][r];
    }



// another similar approach
class Solution{
public:
    int nCr(int n, int r){
       int p=1000000007;
     long long C[r+1]={0};
    C[0]=1;
    for(int  i=0;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
        C[j]=(C[j]+C[j-1])%1000000007;
      }
      return C[r];
     //commented out portion also works
    // int i,j;
    // vector<vector<int>> dp(n+1,vector<int>(r+1,0));
    
    //  for(int i=0;i<=n;i++){
    //      dp[i][0]=1;
    //  }
   
    // for(int i=0;i<=n;i++){
    //     for(int j=1;j<=min(i,r);j++){/// when i=0 j loop dont work
           
    //  dp[i][j]=(dp[i-1][j]%p + dp[i-1][j-1]%p)%p;
    //     }
    // }
    
    // return dp[n][r];
     }
};
