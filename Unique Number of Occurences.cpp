class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
           
            mp[arr[i]]++;
            
            
        }
        
        vector<int> freq(n+1);
        
        for(auto it : mp){
            if(freq[it.second]==1)
            return false;
            
            else
            freq[it.second]=1;
        }
        
        
        return true;
        
    }
};
