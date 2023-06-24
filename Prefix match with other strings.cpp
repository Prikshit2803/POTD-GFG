class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        string ap="";
        int ans=0;
        for(int i=0;i<k;i++){
            ap+=str[i];
            //cout<<ap<<" ";
        }
        
        for(int j=0;j<n;j++){
            //int flag=0;
            // for(int i=0;i<k;i++){
            // if(arr[j][i]!=ap[i]){
            //     flag=1;
            //     break;
            // } ********** This works but a better way is possible
        // }
        
        // if(flag==0)
        // ans++;
            
            if(arr[j].substr(0,k)==ap)
            ans++;
            
        }
        
        return ans;
    }
};
