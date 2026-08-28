class LRUCache {
public:
    // Implementation of a Doubly Linked List Data Structure and using Hashmaps
    class ListNode{
        public:
            int key,val;
            ListNode* next;
            ListNode* prev;
            ListNode(int k,int v){
                key=k;
                val=v;
                prev=NULL;
                next=NULL;
    }
    };

    ListNode* head=new ListNode(-1,-1);// Next to head will store Most recently stored pair
    ListNode* tail=new ListNode(-1,-1);// Prev to Tail will store LRU pair
    unordered_map<int,ListNode*> m;
int limit;
    void addNode(ListNode* Newnode){
        ListNode* headnext=head->next;
        head->next=Newnode; headnext->prev=Newnode;
        Newnode->prev=head; Newnode->next=headnext;
    }
    void delNode(ListNode* Newnode){
        ListNode* Prev=Newnode->prev;
        ListNode* Next=Newnode->next;
        Prev->next=Next;
        Next->prev=Prev;
    }

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){return -1;}
        int keyval=m[key]->val;
        ListNode* ansNode=m[key];
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;
        return keyval;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            delNode(m[key]);
            m.erase(key);// Update the value of Key if the key exists.
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
            // Erase function is used to remove a key-value pair from a map.
        }
        ListNode* Newnode=new ListNode(key,value);
        addNode(Newnode);
        m[key]=Newnode;
    }
};
