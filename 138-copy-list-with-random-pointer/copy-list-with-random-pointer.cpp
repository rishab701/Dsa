/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==NULL){
           return head;
       }
       //Copy a LinkedList first
       Node*new_head=new Node(0);
       Node*new_curr=new_head;
       Node*curr=head;
       unordered_map<Node*,Node*>umap;
       while(curr){
           Node*temp=new Node(curr->val);
           umap.insert({curr,temp});
           
           new_curr->next=temp;
           new_curr=new_curr->next;
           curr=curr->next;
       }
       curr=head;
       new_curr=new_head->next;
       while(curr){
           Node*random=curr->random;
           //Find alternative of random in our new made LinkedList
           Node*newNode=umap[random];
           new_curr->random=newNode;
           new_curr=new_curr->next;
           curr=curr->next;
       }
       return new_head->next;
    }
};