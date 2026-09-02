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
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* Newnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=Newnode;
        }
        return prev;
    }
    ListNode* findkthnode(ListNode* head,int k){
        while(head!=nullptr && k>1){
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=nullptr;
        while(temp!=nullptr){
        if(findkthnode(temp,k)==NULL){
            if(!prevnode){head=temp;}
            else{prevnode->next=temp;}
            break;
        }
        ListNode* kth=findkthnode(temp,k);
        ListNode* Nextnode=kth->next;
        kth->next=nullptr;
        reversell(temp);
        if(temp==head){head=kth;}
        else{prevnode->next=kth;}
        prevnode=temp;
        temp=Nextnode;
        }
        return head;
    }
};
