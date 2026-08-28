class LRUCache {
public:
    class ListNode{
        public:
            int key,val;
            ListNode* next,*prev;
            ListNode(int k,int v){
            key=k;
            val=v;
            next=NULL;prev=NULL;
        }
    };
    unordered_map<int,ListNode*> m;
    ListNode* head=new ListNode(-1,-1);
    ListNode* tail=new ListNode(-1,-1);
    int limit;
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(ListNode* Newnode){
        ListNode* headnext=head->next;
        head->next=Newnode; headnext->prev=Newnode;
        Newnode->prev=head; Newnode->next=headnext;
    }
    void delNode(ListNode* Newnode){
        ListNode* Prev=Newnode->prev;
        ListNode* Next=Newnode->next;
        Prev->next=Next; Next->prev=Prev;
    }
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        ListNode* keyval=m[key];
        m.erase(key);
        delNode(keyval);
        addNode(keyval);
        m[key]=keyval;
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
             delNode(m[key]);
            m.erase(key);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        ListNode* Newnode=new ListNode(key,value);
        addNode(Newnode);// I forgot that I did create addNode function and repeated the steps inside it here.
        m[key]=Newnode;
    }
};
