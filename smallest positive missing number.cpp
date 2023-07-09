class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        vector<int> ap(n+2,0); 
        
        //both set and vector work
        set<int> st;

for(int i=0; i<n; i++){
    if(arr[i]>0 && arr[i]<=n)
    ap[arr[i]]=1;
    //cout<<arr[i]<<":";
    //st.insert(arr[i]);
}        
       
       for(int i=1;i<=n;i++){
             //if(st.find(i) ==st.end()) 
             if(ap[i]==0)
             return i;
       } 
       
       return n+1;
        
        
        
    } 
};

//another approach with O(!) time complexity
 int i = 0;
        while(i<n){
            if(arr[i]>0 and arr[i]<=n and arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }
            else i++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1)return i+1;
        }
        return n+1;
