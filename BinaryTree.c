#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***
* A binary tree has a few operations, insert a new node, delete a node
 * (1. Here is where the work lies)
 * It depends on recursion to traverse the tree
 * Left < root :: right > root
*/

struct node {
    int key;
    struct node *left, *right;
};

/***
 * creating a node
 * @param item
 * @return
 */
struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/***
 * @param root
 */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);

        printf(" %d\n", root->key);

        inorder(root->right);

//        printf("second %d\n", root->key);

    }

}

//insert a node
/**
 *
 * @param node
 * @param key
 * @return
 */
struct node *insert(struct node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;

}

/**
 * Find the left most value of the trr
 * @param node
 * @return
 */
struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
/**
 *
 * @param root
 * @param key
 * @return
 */
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;

        }
//    if node has two children
        struct node *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;


}

int main() {
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    inorder(root);
}