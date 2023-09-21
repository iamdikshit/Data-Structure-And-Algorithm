/*
	Class Based Implement of Trie
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
	public:
		bool isEndString;
		TrieNode *child[26];

		// constructor
		TrieNode(){
			this->isEndString = false;
			for(int i=0;i<26; i++)
			{
				this->child[i] = NULL;
			}
		}
		
		

		void Insert(string word)
		{
			if(word.length()<=0) return;
			TrieNode *temp = this;

			for(int i=0; i<word.length(); i++)
			{
				int index = word[i] - 'a';
				if(!temp->child[index]){
					TrieNode *newNode = new TrieNode();
					temp->child[index] = newNode;
					cout<<word[i]<<" inserted successfully"<<endl;
				}
				temp = temp->child[index];
			}
			temp->isEndString = true;
		}

		// search function
		bool search(string word){
			if(word.length()<=0) return false;
			TrieNode *temp = this;
			for(int i=0; i<word.length(); i++)
			{
				int index = word[i] - 'a';
				if(temp->child[index] && i<=word.length()-1){
					temp = temp->child[index];
				}
				else{
					return false;
				}
			}
			return temp->isEndString;
		}

		// search word with starting prefix
		bool startWith(string word)
		{
			if(word.length()<=0) return false;
			TrieNode *temp = this;
			for(int i=0;i<word.length();i++)
			{
				int index = word[i] - 'a';
				if(!temp->child[index] && i<word.length())
				{
					return false;
				}
				temp = temp->child[index];
			}
			return true;
		}
};



int main()
{
	TrieNode *root = new TrieNode;
	string word,key,key2;
	cin>>word;
	root->Insert(word);
	cout<<"\nEnter word to search:";
	cin>>key;
	if(root->search(key))
		cout<<key<<" is present;"<<endl;
	else
		cout<<key<<" is not present"<<endl;
		
	cout<<"\nEnter prefix to search:";
	cin>>key2;
	if(root->startWith(key2))
		cout<<key2<<" is present;"<<endl;
	else
		cout<<key2<<" is not present"<<endl;
	
	return 0;
}
