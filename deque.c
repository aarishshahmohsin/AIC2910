#include <stdio.h>

#define max 1000
int deque[max];

int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

void push_front(int value) {
    if (front == 0 && rear == max - 1) {
        printf("overflow\n");
    }
    else if (front == rear + 1){
        printf("overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        deque[0] = value;
    }
    else if (front == 0) {
        front = max - 1;
        deque[front] = value;
    }
    else {
        front--;
        deque[front] = value;
    }
}

void push_back(int value) {
    if (front == 0 && rear == max -1 ) {
        printf("overflow\n");
    } else if (rear == front-1) {
        printf("overflow\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        deque[0] = value;
    } else if (rear == max-1) {
        rear = 0;
        deque[rear] = value;
    } else {
        rear++;
        deque[rear] = value;
    }
}

void pop_front() {
    if (isEmpty()) {
        printf("empty\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == max -1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("empty\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = max-1;
    } else {
        rear--;
    }
}



void get_front() {
    if (isEmpty()) {
        printf("empty\n");
        return;
    }
    printf("%d\n", deque[front]);
}

void get_back() {
    if (isEmpty()) {
        printf("empty\n");
        return;
    }
    printf("%d\n", deque[rear]);
}


int main() {

    while (1) {
        printf("push_front(1), push_back(2), pop_front(3), pop_back(4), front(5), back(6), terminate(0)\n");
        int x;
        scanf("%d", &x);
        if (x == 0) {
            printf("the program has been succesfully terminated\n");
            break;
        } else if (x == 1) {
            printf("enter the value\n");
            int val;
            scanf("%d", &val);
            push_front(val);
        } else if (x == 2) {
            printf("enter the value\n");
            int val;
            scanf("%d", &val);
            push_back(val);
        } else if (x == 3) {
            pop_front();
        } else if (x == 4) {
            pop_back();
        } else if (x == 5) {
            get_front();
        } else if (x == 6) {
            get_back();
        } else {
            printf("enter a valid option\n");
        }
    }

    return 0;
}
