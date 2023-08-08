//simplify and store in map and for each element check if 1 - 'element' exists
int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<double,int> mp;
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            
            int gcd=__gcd(numerator[i],denominator[i]); //inbuilt function
            
            int nm=numerator[i]/gcd;
            int dm=denominator[i]/gcd; //simplifies to lowest terms both numerator and denominator
            
            double x=(double)nm/dm;
            double y=(double)(dm-nm)/dm; //1-x
            
            if(mp[y]>0)
            cnt+=mp[y];
            
            mp[x]++;
        }
        
        return cnt;
    }
