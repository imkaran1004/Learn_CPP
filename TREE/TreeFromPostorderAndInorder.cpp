/*
Algorithm:
1. start from the end of postorder & pick aan element to create a node
2. decrement postorder index
3. search for picked element's position in inorder
4. call to built right subtree from inorder's pos+1 to n
5. call to built left subtree from inorder's 0 to pos-1
6. return the node
*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;  

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[],int inorder[],int start,int end){
    static int idx=4;
    if(start>end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    Node* curr=new Node(val);
    if(start==end){
        return curr;
    }
    int pos=search(inorder,start,end,val);
    curr->right=buildTree(postorder,inorder,pos+1,end);
    curr->left=buildTree(postorder,inorder,start,pos-1);
    return curr;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    Node* root=buildTree(postorder,inorder,0,4);
    inorderPrint(root);
    return 0;
}