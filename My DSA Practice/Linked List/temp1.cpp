// mine
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
        if (m.find(key)!=m.end()){ // key is found so putting it at front of linked list.

            Node *prev=m[key]->prev; // removing the key from the chain.
            Node *next=m[key]->next;
            if (prev!=NULL)
            prev->next=next;
            if (next!=NULL)
            next->prev=prev;
            m[key]->next=head; // putting this key at the front of the linked list.
            m[key]->prev=NULL;
            head=m[key];
            return m[key]->value;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (m.find(key)!=m.end()){ // key is found so putting it at front.
            Node *prev=m[key]->prev;// same procedure as in above implementation.
            Node *next=m[key]->next;
            if (prev!=NULL)
            prev->next=next;
            if (next!=NULL)
            next->prev=prev;
            m[key]->next=head;
            m[key]->prev=NULL;
            head=m[key];
        } 
        else{ // key not found so making a new node with this key.
            Node *temp=new Node(key, value);
            m.insert({key, temp});
            if (curr==size){
                if (head==tail){
                delete tail;
                head=temp;
                tail=head;
                }
                else{
                Node *prev=tail->prev;
                prev->next=NULL;
                m.erase(tail->key);
                    delete tail;
                tail=prev;
                temp->next=head;
                head->prev=temp;
                head=temp;
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
                curr++;
            }
        }
    }
};