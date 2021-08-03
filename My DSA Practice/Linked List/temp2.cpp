struct Node{
    int key, value;
    Node *next, *prev;
    Node(int x, int y){
        key=x;
        value=y;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache
{
    private:

    public:

    int size, curr; // size is total capacity and curr is current size.

    Node *head, *tail; // tail and head of cache memory.

    unordered_map<int, Node*> m; // to store points to each keys.

    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size=cap;
        curr=0;
        head=NULL;
        tail=NULL;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (m.count(key)!=0){ // key is found so putting it at front of linked list.
            if(m[key]==head){
                //cout<<"ok";
                return m[key]->value;
            }
            Node *prev=m[key]->prev; // removing the key from the chain.
            Node *next=m[key]->next;
            if (prev!=NULL)
            prev->next=next;
            if (next!=NULL)
            next->prev=prev;
            m[key]->next=head;
            head->prev = m[key];
            // m[key] can be the tail so we need to update tail too.
            if(m[key]==tail and prev){
                tail = prev;
            }else if(m[key] == tail){
                tail = head;
            }
            m[key]->prev=NULL;
            head=m[key];
            Node* temp = head;
            //cout<<"ok";
            return m[key]->value;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (m.count(key)!=0){ // key is found so putting it at front.
            if(m[key]==head){
                m[key]->value = value;
                return;
            }
            Node *prev=m[key]->prev;// same procedure as in above implementation.
            Node *next=m[key]->next;
            if (prev!=NULL)
            prev->next=next;
            if (next!=NULL)
            next->prev=prev;
            
            m[key]->next=head;
            head->prev = m[key];
            // if m[key] is the tail itself then update tail as well
            if(m[key]==tail){
                tail = prev;
            }
            head=m[key];
            // update its value as well
            m[key]->value = value;
            //cout<<"k";
        } 
        else{ // key not found so making a new node with this key.
            Node *temp=new Node(key, value);
            m[key] = temp;
            //cout<<curr<<" ";
            if (curr==size){
                if (head==tail){
                    //cout<<"mist";
                    int deleted = tail->key;
                delete tail;
                head=temp;
                // tail=head;
                // while(tail){
                //     cout<<tail->value<<" ";
                //     tail = tail->next;
                // }
                    m.erase(deleted);
                tail = head;
                }
                else{
                    
                Node *prev=tail->prev;
                prev->next=NULL;
                m.erase(tail->key);
                //delete tail;
                tail=prev;
                temp->next=head;
                head->prev=temp;
                head=temp;
                    //cout<<"huh";
                }
            }
            else if (curr==0){
                head=temp;
                tail=head;
                curr++;
            }
            else{
                temp->next=head;
                head->prev=temp;
                head=temp;
                temp= head;
                curr++;
            }
        }
    }
};