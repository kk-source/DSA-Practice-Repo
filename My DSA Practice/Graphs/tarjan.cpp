#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> adj[], int a, int b){
    adj[a].push_back(b);
}
// st1 is for single recursive call.
// st is for whole program.
void dfs(stack<int> &s, vector<int> adj[], int &ind, int src, unordered_set<int> &st, int low[], int disc[], unordered_set<int> st1){
    low[src]=disc[src]=ind++;
    st.insert(src);
    st1.insert(src);
    s.push(src);
    for (auto i:adj[src]){
        if (st.find(i)==st.end()){
        dfs(s, adj, ind, i, st, low, disc, st1);
        low[src]=min(low[src], low[i]);
        }
        else if (st1.find(i)!=st1.end()){
            low[src]=min(low[src], disc[i]);
        }
    }
    if (low[src]==disc[src]){
        while(s.top()!=src){
            cout << s.top() << " ";
            s.pop();
        }
        cout << s.top() << endl;
        s.pop();
    }
}
void tarjan(vector<int> adj[], int n){
    unordered_set<int> st, st1;
    int ind=1;
    int low[n], disc[n];
    stack<int> s;
    for (int i=0;i<n;i++){
        if (st.find(i)==st.end())
        dfs(s, adj, ind, i, st, low, disc, st1);
    }
}
int main(){
    int n=5;
    vector<int> adj[n];
    insert(adj, 0, 1);
    insert(adj, 1, 2);
    insert(adj, 2, 0);
    insert(adj, 1, 3);
    insert(adj, 3, 4);
    // insert(adj, 4, 2);
    tarjan(adj, n);

    return 0;
}
/*
#include<iostream> 
#include <list> 
#include <stack> 
#define NIL -1 
using namespace std; 


class Graph 
{ 
	int V; 
	list<int> *adj; 

	void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]); 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void SCC(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 


void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]) 
{ 
	static int time = 0; 

	disc[u] = low[u] = ++time; 
	st->push(u); 
	stackMember[u] = true; 
 
	list<int>::iterator i; 
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	{ 
		int v = *i;

		if (disc[v] == -1) 
		{ 
			SCCUtil(v, disc, low, st, stackMember); 

			low[u] = min(low[u], low[v]); 
		} 

		else if (stackMember[v] == true) 
			low[u] = min(low[u], disc[v]); 
	} 

	int w = 0;
	if (low[u] == disc[u]) 
	{ 
		while (st->top() != u) 
		{ 
			w = (int) st->top(); 
			cout << w << " "; 
			stackMember[w] = false; 
			st->pop(); 
		} 
		w = (int) st->top(); 
		cout << w << "\n"; 
		stackMember[w] = false; 
		st->pop(); 
	} 
} 

void Graph::SCC() 
{ 
	int *disc = new int[V]; 
	int *low = new int[V]; 
	bool *stackMember = new bool[V]; 
	stack<int> *st = new stack<int>(); 

	for (int i = 0; i < V; i++) 
	{ 
		disc[i] = NIL; 
		low[i] = NIL; 
		stackMember[i] = false; 
	} 

	for (int i = 0; i < V; i++) 
		if (disc[i] == NIL) 
			SCCUtil(i, disc, low, st, stackMember); 
} 

int main() 
{ 
	cout << "SCCs in the graph \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.SCC(); 

	return 0; 
} 
*/