Node* segregate(Node *head) {
        
       int cnt0=0,cnt1=0,cnt2=0;
       
       Node * cur = head;
       
       while(cur){
           if(cur->data==0){
               cnt0++;
           }
           
           else if(cur->data==1){
               cnt1++;
           }
           
           
           else if(cur->data==2){
               cnt2++;
           }
           
           cur=cur->next;
       }
       
      
       
       cur=head;
       
       for(int i=0;i<cnt0;i++){
           head->data=0;
           head=head->next;
       }
       
       for(int i=0;i<cnt1;i++){
           head->data=1;
           head=head->next;
       }
       
       for(int i=0;i<cnt2;i++){
           head->data=2;
           head=head->next;
       }
        
        return cur;
    }

// Another APPROACH :

// 1. HAVE USE VECTOR DATA TYPE TO STORE THE PRESENT VALUE'S OF THE LL

// 2. AFTER THAT HAVE SORT OUT THE VALUE AND THEN INPUT ASS IT IS TO THE LL.

// 3. THUS GOT THE SORTED LL.

CODE:


class Solution
{
    private:
   

void sortLinkedList(Node *&head)
{
    vector<int> elements;
    Node *temp = head;
    while (temp != NULL)
    {
        elements.push_back(temp->data);
        temp = temp->next;
    }

    sort(elements.begin(), elements.end());

    temp = head;
    for (size_t i = 0; i < elements.size(); i++)
    {
        temp->data = elements[i];
        temp = temp->next;
    }
}   

public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        
        // Add code here
        sortLinkedList(head);
        
       

        return head;
        
        
    }
