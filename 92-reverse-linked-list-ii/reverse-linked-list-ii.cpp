/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){
            return NULL;
        }
        vector<int>ans;
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
            cnt++;
        }
        left--;
        reverse(ans.begin()+left,ans.begin()+right);
        ListNode*dummy=new ListNode(0);
        ListNode*curr=dummy;
        for(int i=0;i<ans.size();i++){
            curr->next=new ListNode(ans[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};