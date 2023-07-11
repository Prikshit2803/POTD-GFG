CODE EXPLAINED ::
~  Take  4 pointers TOP , BOTTOM , LEFT , RIGHT .
~ TOP and BOTTOM are associated with row & LEFT and RIGHT are associated with column.

~ Initialise  TOP = 0 (first row) , BOTTOM = N-1 (last row) , LEFT=0 (first column) ,
    RIGHT=M-1(last column).

~Take a cnt variable to keep track of k-th element while traversing spirally.

~ We take a while loop and run until top and bottom pointers doesn't get crossed similarly right and left pointers doesn't get crossed. 

~ In for loop 1

         - we move from left to right 

         - Increment cnt variable and if cnt==k return that element in matrix

         - Note while next traversal of this loop we doesn't traverse the same row  (from                           beginning) again, we  traverse  from next row hence do TOP ++

 

~ In for loop 2

         - we move from top to bottom

         - Increment cnt variable and if cnt==k return that element in matrix

         - Note while next traversal of this loop we doesn't traverse the same column (from end)               again,  hence do RIGHT --                   

 

~ In for loop 3

         - we move from right to left 

         - Increment cnt variable and if cnt==k return that element in matrix

         - Note while next traversal of this loop we doesn't traverse the same row (from end)                     again, hence do BOTTOM -- 

     

~ In for loop 4

         - we move from bottom to top

         - Increment cnt variable and if cnt==k return that element in matrix

         - Note while next traversal of this loop we doesn't traverse the same column (from                       beginning ) again,  hence do LEFT ++  

 

~ When finally while loop ends we get the kth element in matrix by spiral traversing .



class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int top=0;
 		int bottom=n-1;
 		int left=0;
 		int right=m-1;
 		
 		int cnt=0;
 		
 		
 		while(top<=bottom && left<=right){
 		    for(int i=left;i<=right;i++){
 		        cnt++;
 		        
 		        if(cnt==k)
 		    return a[top][i]; 		    
 		        
 		    }
 		    
 		    top++;
 		    
 		    for(int i=top;i<=bottom;i++){
 		         cnt++;
 		        
 		        if(cnt==k)
 		    return a[i][right]; 
 		    }
 		    
 		    right--;
 		    
 		    if(top<=bottom){
 		        for(int i=right;i>=left;i--){
 		            cnt++;
 		        
 		        if(cnt==k)
 		    return a[bottom][i]; 
 		        }
 		        
 		        bottom--;
 		    }
 		    
 		    if(left<=right){
 		        for(int i=bottom;i>=top;i--){
 		             cnt++;
 		        
 		        if(cnt==k)
 		     return a[i][left]; 
 		        }
 		        
 		        left++;
 		    }
 		}
 		
 		return 0;


    }
};
