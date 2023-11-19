#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
}

node *search(node *root, int data)
{
	if (root == NULL) {
	}
    while (root != NULL) {
        if (data < root->data) {
            root = root->left;
        }
        else if (data > root->data) {
            root = root->right;
        }
        else {
            break;
        }
    }
    return root;
}

node *findMin(node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

node *delete(node *root, int data)
{
	if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

int main()
{

    node * root = NULL;

    while (1) {
        printf("Enter(1) or Search(2) or Delete(3)");
        int x;
        scanf("%d", &x);
        if (x == 1) {
            printf("enter the data\n");
            int data;
            scanf("%d", &data);
            if (root == NULL) {
                root = createNode(data);
            }
            else {
                insert(root, data);
            }
        }
        else if (x == 2){
            printf("enter the data\n");
            int data;
            scanf("%d", &data);
			if (root == NULL) {
				printf("no node in the tree\n");
			} else {
				node * result = search(root, data);
				if (result == NULL) {
					printf("Node not found\n");
				} else {
					printf("Node is present\n");
				}
			}
        } else if (x == 3) {
			printf("enter the data\n");
			int data;
			scanf("%d", &data);
			root = delete(root, data);
		} else {
			printf("enter a valid option\n");
		}
    }

    return 0;
}
