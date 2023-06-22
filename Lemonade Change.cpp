// my soln
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        vector<int> sum(3,0);
        sum[0]=0;
        sum[1]=0;
        sum[2]=0;
        
        if(bills[0]==10||bills[0]==20)
        return false;
        
        for(int i=0;i<N;i++){
            if(bills[i]==5){
                sum[0]++;
            }
            
           else if(bills[i]==10){
                sum[0]--;
                sum[1]++;
            }
            
            else if(bills[i]==20){
               
               // if(sum[0]>=3) sum[0]=sum[0]-3; This condition as first fails as consider a situation of 5 5 5 10 20 10 
               
                 if(sum[1]>=1 && sum[0]>=1){
                    sum[0]--;
                    sum[1]--;
                }
                
                 else if(sum[0]>=3) sum[0]=sum[0]-3; // this should should be preffered less as $5 notes are mpre important
                    
                    else
                    return false;
                }
            
            
            if(sum[0]<0 || sum[1]<0)
            return false;
        }
        
        return true;
        
        }
        
        
    
};

// better soln that uses no memory as ten and five can be used as variable
bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        int five=0,ten=0;
        for(int i=0;i<n;i++){
            if(bills[i]==20){
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
            else if(bills[i]==10){
                ten++;
                if(five)five--;
                else return false;
            }
            else five++;
        }
        return true;
    }
