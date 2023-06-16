//dp
class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {

        //NOTE: The problem is which fruit to select first among the multiple fruits of same type. If we look carefully
        // then you will find that you don't have multiple options but just two options which is leftmost and rightmost
        //because if you are going either of the way then you will surely be collecting the fruits coming to your way
        //so you don't have to worry about the fruits in between but just fruits at leftmost and rightmost location of
        //a particular type.
        
        //Approach : Here we are going to use type no. as index and for every type we will be storing the left most 
        // fruit (at sub-index 0) and right most fruit (at sub-index 1) of that type.
        //After that we will be using a dp array(type based indexing) for storing the minimum distance when and if we start
        // from that position to move forward
        
        int maxi = 0;
        
        //finding the maximum type no.
        for(int i=0; i<n;i++)
            maxi = max(maxi, types[i]);
        
        vector<vector<int>>val(maxi+1, vector<int>(2,INT_MAX));//here we are storing the left most and right most location of a type of fruit
        
        //storing the left most and right most locations of a particular type of fruit
        for(int i=0; i<n; i++){
            if(val[types[i]][0] == INT_MAX){
                val[types[i]][0] = locations[i];
                val[types[i]][1] = locations[i];
            }
            else{
                if(val[types[i]][0] > locations[i])
                    val[types[i]][0] = locations[i];
                if(val[types[i]][1] < locations[i])
                    val[types[i]][1] = locations[i];
            }
        }
        
        vector<vector<long long>>dp(maxi+1, vector<long long>(2));
        
        //base condition
        //For fruits with maximum type no.
        //For taking left most fruit first we will add the distance b/w leftmost and rightmost and then distance for returning back to 0
        dp[maxi][0] = abs(val[maxi][0] - val[maxi][1]) + abs(val[maxi][1] - 0);//last type left to right and then back to 0
        //For taking right most fruit first we will add the distance b/w rightmost and leftmost and then distance for returning back to 0
        dp[maxi][1] = abs(val[maxi][1] - val[maxi][0]) + abs(val[maxi][0] - 0);//last type right to left and then back to 0
        n--;//decrementing no. of fruits left i.e. n
        
        int nextInd = maxi;//stores the last valid fruit type
        for(int i = maxi-1; i>=1 && n; i--){//type start from 1 to maxi
            if(val[i][0] == INT_MAX){//not a valid type
                continue;
            }
            else{
                n--;
                //if we start from left most fruit
                dp[i][0] = abs((long long)val[i][0] - val[i][1]) + min (abs((long long)val[i][1] - val[nextInd][0]) + dp[nextInd][0],
                            abs((long long)val[i][1] - val[nextInd][1]) + dp[nextInd][1]);
                //if we start from right most fruit
                dp[i][1] = abs((long long)val[i][1] - val[i][0]) + min (abs((long long)val[i][0] - val[nextInd][0]) + dp[nextInd][0],
                            abs((long long)val[i][0] - val[nextInd][1]) + dp[nextInd][1]);
                nextInd = i;//updating nextInd so that we know what was the last valid fruit type.
            }
        }
        
        return min(dp[nextInd][0] + abs(val[nextInd][0] - 0), dp[nextInd][1] + abs(val[nextInd][1] - 0));//Now returning the answer for the minimum type fruit including the distance I have to travel to reach it from 0.

//Suggestion : Try to visualize the scenario over the number line.

    }
};
