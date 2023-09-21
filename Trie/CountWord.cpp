/*
        Count Number word present in a trie
        Operations:
            Insert
            Search
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    bool isEndOfString;
    int count;
    Node *child[26];
    public:
        Node(){
            this->isEndOfString = false;
            this->count = 0;
            for(int i=0; i<26;i++)
            {
                this->child[i] = NULL;
            }
        }

        void insert(string word)
        {
            if(word.length()<=0) return;
            Node *temp = this;
            for(int i=0;i<word.length();i++)
            {
                int index = word[i] - 'a';
                if(!temp->child[index])
                {
                    Node *newNode = new Node();
                    temp->child[index]=newNode;
                    cout<<word[i]<<" inserted successfully"<<endl;
                }
                temp->count++;
                temp = temp->child[index];
            }
            temp->count++;
            temp->isEndOfString = true;
        }

        int countWord(string word)
        {
            // if(word.length()<=0) return 0;
            Node *temp = this;
            for(int i=0;i<word.length();i++)
            {
                int index = word[i] - 'a';
                if(temp->child[index] && i<=word.length()-1)
                {
                    temp = temp->child[index];
                }
                else{
                    return 0;
                }
            }
            return temp->count;

        }
};


int main(){

    Node *root = new Node();
    string word,key,key2;
    cin>>word;
    root->insert(word);
    cin>>key;
    cout<<root->countWord(key);
    return 0;
}