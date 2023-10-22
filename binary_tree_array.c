#include <stdio.h>

#define MAX 100
#define INF -1e5

int tree[2*MAX+1];

void initialize() {
    for (int i = 0; i < 2*MAX+1; i++) {
        tree[i] = INF;
    }
}

void set_root(int value) {
    tree[0] = value;
}

void set_left(int parent, int value) {
    tree[parent * 2 + 1] = value;
}

void set_right(int parent, int value) {
    tree[parent * 2 + 2] = value;
}

void get_left(int parent) {
    if (tree[parent*2+1] == INF) {
        printf("NO value inserted\n");
        return;
    }
    printf("%d", tree[parent*2+1]);
}

void get_right(int parent) {
    if (tree[parent * 2 + 2] == INF) {
        printf("NO value inserted\n");
        return;
    }
    printf("%d", tree[parent*2+2]);
}

void get_node(int n) {
    if (tree[n] == INF) {
        printf("node not present\n");
        return;
    }
    printf("%d", tree[n]);
}

void delete_node(int n) {
    int i = n * 2 + 1;
    while (i < n) {
        tree[i] = INF;
        i = i * 2 + 1;
    }
    i = n * 2 + 2;
    while (i < n) {
        tree[i] = INF;
        i = i * 2 + 2;
    }
    tree[n] = INF;
}

void print_tree() {
    for (int i = 0; i < 2*MAX+1; i++) {
        if (tree[i] == INF) {
            printf("(empty),");
        } else {
            printf("%d, ", tree[i]);
        }
    }
}

void preorder(int root) {
    if (tree[root] != INF) {
        printf("%d, ", tree[root]);
        preorder(root * 2 + 1);
        preorder(root * 2 + 2);
    }
}

int parent(int node) {
    if (node == 0) {
        printf("root\n");
        return -1;
    }
    if (node % 2 == 0) {
        printf("%d", tree[(node-2)/2]);
        return (node-2)/2;
    } else {
        printf("%d", tree[(node-1)/2]);
        return (node-1)/2;
    }
}

void sibling(int node) {
    if (node == 0) {
        printf("root\n");
        return;
    }

    if (node % 2 == 0) {
        get_left(parent(node));
    } else {
        get_right(parent(node));
    }
}


void inorder(int root) {
    if (tree[root] != INF) {
        preorder(root * 2 + 1);
        printf("%d, ", tree[root]);
        preorder(root * 2 + 2);
    }
}

void postorder(int root) {
    if (tree[root] != INF) {
        preorder(root * 2 + 1);
        preorder(root * 2 + 2);
        printf("%d, ", tree[root]);
    }
}

int main() {
    initialize();
    while (1) {
        printf("insert(1), fetch(2), delete(3), traverse(4), print(5)\n");
        int x;
        scanf("%d", &x);
        if (x == 1) {
            if (tree[0] == INF) {
                printf("There is currently no node in the tree\n");
                printf("insert the root\n");
                int val;
                scanf("%d", &val);
                set_root(val);
            } else {
                printf("set_left(1), set_right(2)\n");
                int x2;
                scanf("%d", &x2);
                if (x2 == 1) {
                    int parent, value;
                    printf("Enter the parent\n");
                    scanf("%d", &parent);
                    printf("Enter the value\n");
                    scanf("%d", &value);
                    set_left(parent, value);
                } else if (x2 == 2) {
                    int parent, value;
                    printf("Enter the parent\n");
                    scanf("%d", &parent);
                    printf("Enter the value\n");
                    scanf("%d", &value);
                    set_right(parent, value);
                } else {
                    printf("enter a valid option\n");
                    continue;
                }
            }
        } else if (x == 2) {
            printf("get_left(1), get_right(2), get_node(3), parent(4), sibling(5)\n");
            int x2;
            scanf("%d", &x2);
            if (x2 == 1) {
                printf("enter the parent\n");
                int parent;
                scanf("%d", &parent);
                get_left(parent);
            } else if (x2 == 2) {
                printf("enter the parent\n");
                int parent;
                scanf("%d", &parent);
                get_right(parent);
            } else if (x2 == 3) {
                printf("enter the node\n");
                int node;
                scanf("%d", &node);
                get_node(node);
            } else if (x2 == 4) {
                printf("enter the node\n");
                int node;
                scanf("%d", &node);
                parent(node);
            } else if (x2 == 5) {
                printf("enter the node\n");
                int node;
                scanf("%d", &node);
                sibling(node);
            } else {
                printf("enter a valid option\n");
                continue;
            }
        } else if (x == 3) {
            printf("enter a node\n");
            int node;
            scanf("%d", &node);
            delete_node(node);
        } else if (x == 4) {
            printf("preorder(1), inorder(2), postorder(3)\n");
            int x2;
            scanf("%d", &x2);
            if (x2 == 1) {
                preorder(0);
            } else if (x2 == 2) {
                inorder(0);
            } else if (x2 == 3) {
                postorder(0);
            } else {
                printf("enter a valid option\n");
                continue;
            }
        } else if (x == 5) {
            print_tree();
        } else {
            printf("enter a valid option\n");
        }
        printf("\n");
    }




}
