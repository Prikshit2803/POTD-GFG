// Check gfg hint for better explaination of approach
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    //Approach : Dividend = Divisor * quotient + remainer ..... modulo with N gives the remainder which is the original element and after dividing by N we get the quotient as answer
    void arrange(long long arr[], int n) {
        
        for(int i=0;i<n;i++){
            arr[i]=((arr[arr[i]]%n)*n + arr[i]);  //we add the current element so that it can be rrestored by modulp i.e. remaindern
        }
        
         for(int i=0;i<n;i++){
            arr[i]=arr[i]/n; // we divide by n to get the quotient as it had the answer
        }
    }
};


// Same approach
void arrange(long long arr[], int n) {
        for( int i = 0; i<n; i++ ){
            int real = arr[i]%n;
            arr[i] += ( arr[real]%n ) * n;
        }
        
        for( int i = 0; i<n; i++ ) arr[i] /= n;
    }
