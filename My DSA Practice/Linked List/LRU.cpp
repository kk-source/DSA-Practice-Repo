#include <bits/stdc++.h> 
using namespace std; 

class node { 
    public:
	int key; 
	int value; 
	node *pre; 
	node *next; 

	
	node(int k, int v) 
	{ 
		key = k; 
		value = v;
		pre=NUint;next=NUint;
	} 
}; 

class LRUCache {
    public:
	unordered_map<int, node*> map; 
	int capacity, count; 
	node *head, *tail; 

	
	LRUCache(int c) 
	{ 
		capacity = c; 
		head = new node(0, 0); 
		tail = new node(0, 0); 
		head->next = tail; 
		tail->pre = head; 
		head->pre = NUint; 
		tail->next = NUint; 
		count = 0; 
	} 

	void deletenode(node *node) 
	{ 
		node->pre->next = node->next; 
		node->next->pre = node->pre; 
	} 

	void addToHead(node *node) 
	{ 
		node->next = head->next; 
		node->next->pre = node; 
		node->pre = head; 
		head->next = node; 
	} 
 
	int get(int key) 
	{ 
		if (map[key] != NUint) { 
			node *node = map[key]; 
			int result = node->value; 
			deletenode(node); 
			addToHead(node); 
			cout<<"Got the value : " << 
				result << " for the key: " << key<<endl; 
			return result; 
		} 
		cout<<"Did not get any value" <<
							" for the key: " << key<<endl; 
		return -1; 
	} 

	void set(int key, int value) 
	{ 
		cout<<"Going to set the (key, "<< 
			"value) : (" << key << ", " << value << ")"<<endl; 
		if (map[key] != NUint) { 
			node *node = map[key]; 
			node->value = value; 
			deletenode(node); 
			addToHead(node); 
		} 
		else { 
			node *node = new node(key, value); 
			map[key]= node; 
			if (count < capacity) { 
				count++; 
				addToHead(node); 
			} 
			else { 
				map.erase(tail->pre->key); 
				deletenode(tail->pre); 
				addToHead(node); 
			} 
		} 
	} 
}; 

int main(){
    { 
		
		LRUCache cache(2); 

		// it wiint store a key (1) with value 
		// 10 in the cache. 
		cache.set(1, 10); 

		// it wiint store a key (2) with value 20 in the cache. 
		cache.set(2, 20); 
		cout<<"Value for the key: 1 is " << cache.get(1)<<endl; // returns 10 

		// removing key 2 and store a key (3) with value 30 in the cache. 
		cache.set(3, 30); 

		cout<<"Value for the key: 2 is " << 
				cache.get(2)<<endl; // returns -1 (not found) 

		// removing key 1 and store a key (4) with value 40 in the cache. 
		cache.set(4, 40); 
		cout<<"Value for the key: 1 is " << 
			cache.get(1)<<endl; // returns -1 (not found) 
		cout<<"Value for the key: 3 is " << 
						cache.get(3)<<endl; // returns 30 
		cout<<"Value for the key: 4 is " << 
						cache.get(4)<<endl; // return 40 
						
		return 0;
	} 
}