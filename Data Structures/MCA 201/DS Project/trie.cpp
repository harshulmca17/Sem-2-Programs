#include <iostream>
#include <cstdlib>
#include <cstdio>

#define CHAR_SIZE 128
using namespace std;
// A Class representing a Trie node
class Trie
{
public:
    bool isEndOfWord;
    Trie* character[CHAR_SIZE];

    // Constructor
    Trie()
    {
        this->isEndOfWord = false;

        for (int i = 0; i < CHAR_SIZE; i++)
            this->character[i] = nullptr;
    }

    void insert(string);
    bool deletion(Trie*&, string);
    bool search(string);
    bool haveChildren(Trie const*);
};

// Iterative function to insert a key in the Trie
void Trie::insert(string key)
{
    // start from root node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // create a new node if path doesn't exists
        if (curr->character[key[i]] == nullptr)
            curr->character[key[i]] = new Trie();

        // go to next node
        curr = curr->character[key[i]];
    }
    curr->character = "Meaning";
    // mark current node as leaf
    curr->isEndOfWord = true;
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
bool Trie::search(string key)
{
    // return false if Trie is empty
    if (this == nullptr)
        return false;

    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // go to next node
        curr = curr->character[key[i]];

        // if string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return false;
    }
    cout<<"Meaning : "<<curr->character;
    // if current node is a leaf and we have reached the
    // end of the string, return true
    return curr->isEndOfWord;
}

// returns true if given node has any children
bool Trie::haveChildren(Trie const* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return true;    // child found

    return false;
}

// Recursive function to delete a key in the Trie
bool Trie::deletion(Trie*& curr, string key)
{
    // return if Trie is empty
    if (curr == nullptr)
        return false;

    // if we have not reached the end of the key
    if (key.length())
    {
        // recurse for the node corresponding to next character in the key
        // and if it returns true, delete current node (if it is non-leaf)

        if (curr != nullptr &&
            curr->character[key[0]] != nullptr &&
            deletion(curr->character[key[0]], key.substr(1)) &&
            curr->isEndOfWord == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }

    // if we have reached the end of the key
    if (key.length() == 0 && curr->isEndOfWord)
    {
        // if current node is a leaf node and don't have any children
        if (!haveChildren(curr))
        {
            // delete current node
            delete curr;
            curr = nullptr;

            // delete non-leaf parent nodes
            return true;
        }

        // if current node is a leaf node and have children
        else
        {
            // mark current node as non-leaf node (DON'T DELETE IT)
            curr->isEndOfWord = false;

            // don't delete its parent nodes
            return false;
        }
    }

    return false;
}

// C++ implementation of Trie Data Structure - Insertion, Searching and Deletion
int main()
{
    Trie* head = new Trie();
    char ch;
    string str;
    do{
        int in;
        cout<<"\n 1 To Insert";
        cout<<"\n 2 To Search";
        cout<<"\n 3 To Exit\n";
        cin>>in;

        switch(in){
            case 1: cout<<"\n Enter the string : ";
                    cin>>str;
                    head->insert(str);
                    break;
            case 2: cout<<"\n Enter the string : ";
                    cin>>str;
                    if(head->search(str)){
                        cout<<"\nString Found ";
                    }
                    else{
                        cout<<"\n String Not Found ";
                        char a;
                        cout<<"\nWould You Like To Insert The Same String...('Y'es,'N'o)? ";
                        cin>>a;
                        if(a == 'y' || a=='Y'){
                            head->insert(str);
                            cout<<"\nString Insertion Completed ";  
                        }
                        else{
                            cout<<"\nString Insertion Request Rejected ";
                        }
                    }
                    break;
            case 3: exit(0);
            default: cout<<"\nPlease enter a valid option and continue.";
        }
        cout<<"\nWould You Like To continue...('Y'es,'N'o)?";
        cin>>ch;
    }while(ch == 'y');

    return 0;
}