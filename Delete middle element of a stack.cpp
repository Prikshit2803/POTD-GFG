//my-way
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
       stack<int> st;
       
       int n=(sizeOfStack+1)/2; //it was given
       
      int p=sizeOfStack-n;
      
      for(int i=0;i<p;i++){
          st.push(s.top());
          s.pop();
      }
      
      s.pop();
      
      for(int i=0;i<p;i++){
          s.push(st.top());
          st.pop();
      }
    }
};

//without using any structing to store - only recursion stack space
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int sizeOfStack , int count){
        if(count == sizeOfStack/2){
            s.pop();
            return;
        }
        int ele = s.top();
        s.pop();
        
        solve(s,sizeOfStack ,count+1);
        
        s.push(ele);
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        solve(s,sizeOfStack ,0);
        
    }
};

