/*
	Trie data structure 
		Operations
			-Insert
			-Search
			-startwith
*/

#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
	string data;
	bool isEndOfString;
	TrieNode *child[26];
};

struct TrieNode *getNode(){
	struct TrieNode *newNode = new TrieNode;
	newNode->isEndOfString = false;
	for(int i= 0; i<26;i++)
	{
		newNode->child[i] = NULL;
	}
	return newNode;
}

void insert( struct TrieNode *root,string word)
{
	if(word.length()<=0) return;
	
	struct TrieNode *newNode = root;
	// root node does not exists
	for(int i=0; i<word.length();i++)
	{
		int index = word[i]-'a';
		if(!newNode->child[index])
		{
			cout<<word[i]<<" inserted successfully"<<endl;	
			newNode->data = word[i];
			newNode->child[index] = getNode();
		}
		newNode = newNode->child[index];
	}
	newNode->isEndOfString = true;
	
}

// Search in tries

bool search(struct TrieNode *root,string key)
{
	if(key.length()<=0) return false;
	struct TrieNode *temp = root;
	
	for(int i=0;i<key.length();i++)
	{
		int index = key[i]-'a';
		
		if(!temp->child[index] && i==key.length()-1)
		{
			break;
		}
		else{
		
			temp = temp->child[index];
		}
		
	}
	
	return temp->isEndOfString;
}

void startWith(struct TrieNode *root,string key)
{
	if(key.length()<=0)
	{
		cout<<"\nKey is empty"<<endl;
		return;
	} 
	struct TrieNode *temp = root;
	int count=1;
	for(int i=0; i<key.length();i++)
	{
		//index
		
		int index = key[i]-'a';
		if(!temp->child[index])
		{
			count++;
			break;
		}
		
		temp = temp->child[index];
	
	}
	
	if(count==1)
	{
		cout<<key<<" present";
	}
	else
	{
		cout<<key<<" not Present";
	}

}


int main(){
	struct TrieNode *root = getNode();
	
	// Insert Input takes word
	string word;
	cin>>word;	
	cout<<word.length()<<endl;	
	insert(root,word);
	
	string key;
	cin>>key;
	bool result = search(root,key);
	if(result)
	{
		cout<<key<<" present";
	}
	else
	{
		cout<<key<<" not Present";
	}
	cout<<endl;
	string key2;
	cin>>key2;
	startWith(root,key2);

	
	
	return 0;
}
