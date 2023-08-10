/*
STUDENT NAME: Trung Tin Le                           CS-22 Data Structures and Algorithms
SEMESTER: Spring 2022                                       PROFESSOR THURSTON
SECTION: 333778
ASSIGNMENT #10
-------------------------------------------------------------------------------------------
Instructions
-------------------------------------------------------------------------------------------
[COPY FROM CANVAS]


*/


#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

//comparator function to make case insensitive comparisions
bool comp(char s1, char s2)
{
    return tolower(s1) < tolower(s2);
}

// the following class would store the words in a BST
class BSTNode
{
public:
    string name;
    BSTNode *left, *right;
    // default constructor
    BSTNode()
    {
    }
    BSTNode(string n)
    {
        name = n;
        left = NULL;
        right = NULL;
    }
    BSTNode*GetnewNode(string name)
    {
        BSTNode* newNode = new BSTNode();
        newNode->name = name;
        newNode->left = newNode->right = NULL;
            return newNode;
    }

    //function to insert a word into the BST
    map<string, bool>P;
    map<string, int>mp;
    BSTNode* insert(BSTNode *root, string n)
    {
        if(root == NULL)
        {
            transform(n.begin(), n.end(), n.begin(), ::tolower);
            mp[n]++;
            return new BSTNode(n);
        }
        //function compares two strings for alphabetical order
        if(lexicographical_compare(root->name.begin(), root->name.end(), n.begin(), n.end(), comp))
        {
            root->right = insert(root->right, n);
        }
        else
        {
            root->left = insert(root->left, n);
        }
        return root;
    }
    bool search(BSTNode* root, string name)
    {
        if(root == NULL)
            return false;
        else if(root->name == name)
            return true;
        else if (name<=root->name)
            return search(root->left,name);
        else return search(root->right,name);
    }

    void inOrder(BSTNode *root)
    {
        if(root == NULL)
            return;
            inOrder(root->left);
        if(root->name != "" && !P[root->name])
        {
            cout<<root->name<<' '<<mp[root->name]<<endl;
            P[root->name] = true;
        }
        inOrder(root->right);
    }
};

int main()
{
    fstream file;
    string fileName = "USconstitutionWords.txt";
    file.open(fileName.c_str());

    cout<<"Enter word \n";
    string Key;
    cin>>Key;

    BSTNode x, *root = NULL, *Search = NULL;
    root = x.insert(root, "");

    string word;
    while(file>>word)
    x.insert(root, word);
    x.inOrder(root);
    x.search(root, word);

    if(Search)
    cout<<"Found\n";
    else cout<<"Not Found\n";
    return 0;
}
