#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool isBST(struct node* root, struct node* minNode, struct node* maxNode){
    if(root == NULL){
        return true;
    }
    if((minNode && root->data<=minNode->data) || (maxNode && root->data>=maxNode->data)){
        return false;
    }
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}

int main()
{
    struct node* root = newNode(45);
    root->left = newNode(15);
    root->right = newNode(79);
    root->left->left = newNode(10);
    root->left->right = newNode(20);
    root->left->left->right = newNode(12);

    root->right->left = newNode(55);
    root->right->left->left = newNode(50);
    root->right->right = newNode(90);

    if (isBST(root, NULL, NULL))
        printf("Your Given Tree Is a BST");
    else
        printf("Your Given Tree Is Not a BST");

    return 0;
}
