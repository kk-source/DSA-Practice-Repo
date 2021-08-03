#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for (int i=0;i<26;i++)
            child[i]=NULL;
    }
    void insert(string &str){
        if (child[str[0]-'a']==NULL)
        child[str[0]-'a']=new TrieNode();
        TrieNode *temp=child[str[0]-'a'];

        for (int i=1;i<str.size();i++){
            if (temp->child[str[i]-'a']==NULL)
            temp->child[str[i]-'a']=new TrieNode();

            temp=temp->child[str[i]-'a'];
        }
            temp->isEnd=true;
    }
    bool search(string &str){
        if (child[str[0]-'a']==NULL)
        return false;
        TrieNode *temp=child[str[0]-'a'];

        for (int i=1;i<str.size();i++){
            if (temp->child[str[i]-'a']==NULL)
            return false;

            temp=temp->child[str[i]-'a'];
        }
        return temp->isEnd;
    }
};
int main(){
    TrieNode tn;
    tn.insert("geek");
    tn.insert("geeks");
    cout << tn.search("geek") << tn.search("gee");

    return 0;
}