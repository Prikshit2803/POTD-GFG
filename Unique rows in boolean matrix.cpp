class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>> ans;
       // vector<int> dup(row,0),cp;
        
        for(int i=0;i<row;i++){
            vector<int> v;
            for(int j=0;j<col;j++){
                v.push_back(M[i][j]);
            }
            
            bool t=false;
            
            for(k : ans){
                if(v==k){
                    t=true;
                    break;
                }
            }
            
            if(t==false) 
            ans.push_back(v);
        }
      
      return ans;
        
   
        
    }
};
