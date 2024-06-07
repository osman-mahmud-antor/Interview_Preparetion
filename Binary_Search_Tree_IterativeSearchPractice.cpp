#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int x){
    struct Node* temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}


struct Node* insert_at_tree(struct Node* node, int data)
{
   if(node == NULL){
        return newNode(data);
   }
   if(data < node->data){
        node->left = insert_at_tree(node->left, data);
   }
   else if(data > node->data){
        node->right = insert_at_tree(node->right, data);
   }

   return node;
}

bool Iterative_Search(struct Node* root, int key){
    while (root != NULL)
    {
        if(key > root->data){
            root = root->right;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            return true;
        }
    }
    return false;
    
}





int main(){
    struct Node* root = NULL;
	root = insert_at_tree(root, 50);
	insert_at_tree(root, 30);
	insert_at_tree(root, 20);
	insert_at_tree(root, 40);
	insert_at_tree(root, 70);
	insert_at_tree(root, 60);
	insert_at_tree(root, 80);
	if (Iterative_Search(root, 15))
		cout << "Yes";
	else
		cout << "No";
	return 0;

}
