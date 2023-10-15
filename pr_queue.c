#include <stdio.h>

#define max 1000

int queue_items[max];
int priority[max];

int max_prior = 0;

int last = -1;

int isEmpty() {
    return last == -1;
}

int isFull() {
    return last == max-1;
}

void insert(int value, int pr) {
    last++;
    queue_items[last] = value;
    priority[last] = pr;
    if (pr > max_prior) {
        max_prior = pr;
    }
    // printf("%d\n", max_prior);
}

int front() {
    for (int i = 0; i <= last; i++) {
        if (priority[i] == max_prior) {
            return i;
        }
    }
    return -1;
}

void pop() {
    int index = front();
    for (int i = index; i < last; i++) {
        priority[i] = priority[i+1];
        queue_items[i] = queue_items[i+1];
    }
    int temp_pr = 0;
    for (int i = 0; i < last; i++) {
        if (priority[i] > temp_pr) {
            temp_pr = priority[i];
        }
    }
    max_prior = temp_pr;
    last--;
}

int main() {

    while (1) {
        printf("Push(1), Pop(2), Front(3), Terminate(0)\n");
        int x;
        scanf("%d", &x);
        if (x == 1) {
            if (isFull()) {
                printf("the queue is full\n");
                continue;
            }
            printf("Enter the value\n");
            int value;
            scanf("%d", &value);
            printf("Enter the Priority\n");
            int p;
            scanf("%d", &p);
            insert(value, p);
        } else if (x == 2) {
            if (isEmpty()) {
                printf("no element present\n");
                continue;
            }
            pop();
        } else if (x == 3) {
            if (isEmpty()) {
                printf("no element present\n");
                continue;
            }
            int i = front();
            printf("Element %d, with priority %d\n", queue_items[i], priority[i]);
            // printf(" i %d\n", i);
            // printf(" last %d\n", last);
        } else if (x == 0) {
            printf("Thank you for using the utility\n");
            break;
        } else {
            printf("enter a valid option\n");
        }
    }




    return 0;
}
