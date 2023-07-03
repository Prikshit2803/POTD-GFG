//Initialize two auxiliary vectors, v_min[ ] and v_max[ ], both of size n
//Calculate the minimum element from the left side for each index i and store it in v_min[ ].
//Calculate the maximum element from the right side for each index i and store it in v_max[ ].
Initialize two pointers, i and j, to track the indices of the array.
//Iterate while i < n and j < n:
//If v_min[i] <= v_max[j], calculate the difference j - i.
//If the calculated difference (j - i) is greater than the current maximum value, update the maximum value.
//Increment j by 1.
//Otherwise, increment i by 1.

    int maxIndexDiff(int arr[], int n) {
        //int maxi=0;
        //brute-force
        
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i]<=arr[j])
        //         maxi=max(j-i,maxi);
                
        //     }
        // }
        
        // return maxi;
        
        vector<int> vmin(n),vmax(n);
        
        vmin[0]=arr[0];
        
        for(int i=1;i<n;i++){
            vmin[i]=min(vmin[i-1],arr[i]);
        }
        
        
        vmax[n-1]=arr[n-1];
        
         for(int i=1;i<n;i++){
            vmax[n-i-1]=max(vmax[n-i],arr[n-i-1]);
        }
        
        int i=0;
        int j=0;
        
        int maxi=0;
        
        while(i<n && j<n){
            if(vmin[i]<=vmax[j]){
                
            maxi=max(j-i,maxi);
            j++;
            }
            else
            i++;
        }
        
        return maxi;
    }

};
