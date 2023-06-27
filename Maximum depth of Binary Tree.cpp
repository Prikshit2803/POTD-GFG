/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this method*/
    int ans=INT_MIN;
    void dfs(Node * root,int depth){
        
       
        
        if(!root)
        return;
        
         ans=max(ans,depth);
        
        
        dfs(root->left,depth+1);
        
        dfs(root->right,depth+1);
        
        
        
    }
    int maxDepth(Node *root) {
        dfs(root,1);
        
        return ans;
        
    }
};
 // another method
class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        // int right=maxDepth(root->right);
        //int left=maxDepth(root->left);
        return max(maxDepth(root->right),maxDepth(root->left))+1;
    }
};
