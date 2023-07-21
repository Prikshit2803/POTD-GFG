 //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
          map<int,int> mp;
          
          Node* cur=head;
          Node *prev=NULL;
          
          while(cur){
              if(mp[cur->data]==1){
                 
                  prev->next=cur->next;
                  cur=cur->next;
              }
              
              else{
                 
                  mp[cur->data]++;
                  prev=cur;
              cur=cur->next;
                   
              }
              
              
          }
          
          return head;
    }
