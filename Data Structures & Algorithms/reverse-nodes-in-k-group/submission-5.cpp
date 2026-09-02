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
    ListNode* reversell(ListNode* head){
        ListNode* temp =head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* Newnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=Newnode;
        }
        return prev;
    }
    ListNode* Findkthnode(ListNode* head,int k){
        while(head!=nullptr && k>1){
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* PrevNode=nullptr;
    ListNode* temp=head;
    while(temp!=nullptr){
    if(Findkthnode(temp,k)==NULL){
        if(!PrevNode){head=temp;}
        else{PrevNode->next=temp;}
        break;
    }
    ListNode* kth=Findkthnode(temp,k);
    ListNode* Nextnode=kth->next;
    kth->next=nullptr;
    reversell(temp);        
    if(temp==head){head=kth;}
    else{
        PrevNode->next=kth;
    }
    PrevNode=temp;
    temp=Nextnode;
   
    } return head;}
};
