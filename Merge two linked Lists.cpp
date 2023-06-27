/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    
    struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data;
    }
};

    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {   
        priority_queue<Node *,vector<Node *>, CompareNodes> pq; //min-heap
        
        Node * cur = head1;
        
        while(cur!=NULL){
            pq.push(cur);
            cur=cur->next;
        }
        
        cur=head2;
        
        while(cur){
            pq.push(cur);
            cur=cur->next;
        }
        
        
        Node * res = pq.top();
        Node * temp=res;
        pq.pop();
        
        while(!pq.empty()){
            Node * tp=pq.top();
            tp->next=NULL; // this is also important
            pq.pop();
            
            if(temp->data!=tp->data){
                temp->next=tp;
                temp=tp;
            }
        }
        
        return res;
    }
};

//Set-based approach
class Solution
{
    public:
  

    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {   
       set<int> s; // unique elements and that too sorted whereas unsorted set has only unique elements but not sorted
       
       Node * cur = head1;
       
       while(cur){
           s.insert(cur->data);
           cur=cur->next;
       }
       
       cur=head2;
       
       while(cur){
           s.insert(cur->data);
           cur=cur->next;
       }
       
       Node * res = new Node(INT_MIN);
       Node * temp = res;
       
       for(auto it : s){
           Node * tp = new Node(it);
           
           temp->next=tp;
           temp=tp;
       }
       
       return res->next;
    }
};
