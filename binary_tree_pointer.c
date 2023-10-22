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
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
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
    if (root == NULL)
    {
        return root;
    }

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

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("Insert(1), Delete(2), Inorder(3), Preorder(4), Postorder(5), Exit(6)\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter data (node number) to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if (choice == 2)
        {
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = delete (root, data);
        }
        else if (choice == 3)
        {
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
        }
        else if (choice == 4)
        {
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
        }
        else if (choice == 5)
        {
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
        }
        else if (choice == 6)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    }
    return 0;
}
