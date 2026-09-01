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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Declaration of Minheap priotity queue
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        // Priority Queue syntax for a min heap data structure.
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){pq.push({lists[i]->val,lists[i]});}
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* temp= dummy;//Mover and attacher node
        while(!pq.empty()){
            auto Min=pq.top();
            pq.pop();
            if(Min.second->next){
                pq.push({Min.second->next->val,Min.second->next});
            }
            temp->next=Min.second;
            temp=temp->next;
        }
        return dummy->next;
        
    }
};
