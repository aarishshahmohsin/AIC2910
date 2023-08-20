/*
problem statement: to implement insertion, deletion, searching in a linked list
using arrays
*/

/*
  @Author: AARISH SHAH MOHSIN
  @Serial No: 2
  @Faculty No: 22AIB126
  @Enrolment No: GM1674
*/

#include <stdio.h>
#include <stdlib.h>

// define the max size for arrays
#define max 500
int link[max];
int info[max];

int avail;

// define arbitrary null value
const int null = -1e4;

// fetches node from avail list for furthe use
int getnode() {
  if (avail == -1) {
    printf("overflow\n");
    return -1;
  }
  int p = avail;
  avail = link[avail];
  return p;
}

// pushes unused node to avail list
void freenode(int p) {
  link[p] = avail;
  avail = p;
  return;
}

// returns the start node
int initialize_linked_list(int data) {
  int start = getnode();
  link[start] = -1;
  info[start] = data;
  return start;
}

// prints the linked list in special format
// () -> () -> () (example)
void print_list(int start) {
  while (link[start] != -1) {
    printf("(%d)->", info[start]);
    start = link[start];
  }
  printf("(%d)\n", info[start]);
}

// returns first location of the target found (1 base indexing)
// else returns -1
int search(int start, int data) {
  int cnt = 1;
  while (link[start] != -1) {
    if (info[start] == data) {
      return cnt;
    }
    cnt++;
    start = link[start];
  }
  if (info[start] == data) {
    return cnt;
  }
  return -1;
}

// insert at passed location
int insert(int *start, int loc, int data) {
  if (loc <= 0) {
    printf("enter a valid loaction\n");
    return 1;
  } else if (loc == 1) {
    int temp = getnode();
    info[temp] = data;
    link[temp] = *start;
    *start = temp;
    return 0;
  } else {
    loc--;
    int cnt = 1;
    int temp = *start;
    while (link[temp] != -1) {
      if (cnt == loc) {
        break;
      }
      temp = link[temp];
      cnt++;
    }
    if (cnt != loc) {
      printf("enter a valid location\n");
      return 1;
    }
    int new_node = getnode();
    info[new_node] = data;
    link[new_node] = link[temp];
    link[temp] = new_node;
    return 0;
  }
}

// insert after the tail node
void insert_at_last(int start, int data) {
  if (info[start] == null) {
    info[start] = data;
    return;
  }
  while (link[start] != -1) {
    start = link[start];
  }
  int x = getnode();
  link[start] = x;
  link[x] = -1;
  info[x] = data;
}

// delete at given location
int delete(int *start, int loc) {
  if (loc <= 0) {
    printf("enter a valid location\n");
    return 1;
  } else if (loc == 1) {
    *start = link[*start];
    return 0;
  } else {
    loc--;
    int cnt = 1;
    int temp = *start;
    while (link[temp] != -1) {
      if (cnt == loc) {
        break;
      }
      temp = link[temp];
      cnt++;
    }
    if (cnt != loc) {
      printf("enter a valid location\n");
      return 1;
    }
    int to_be_deleted = link[temp];
    link[temp] = link[link[temp]];
    freenode(to_be_deleted);
    return 0;
  }
}

// deletes the tail node
int delete_last_elem(int start) {
  if (link[start] == -1) {
    printf("list only contains one node\n");
    return 1;
  }
  while (link[link[start]] != -1) {
    start = link[start];
  }
  freenode(link[start]);
  link[start] = -1;
  return 0;
}

int main() {

  // making all nodes available

  avail = 0;

  for (int i = 0; i < max - 1; i++) {
    link[i] = i + 1;
  }
  link[max - 1] = -1;

  // initializing the linked list i.e. making the start node

  int start = initialize_linked_list(null);

  // driver using infinite while loop

  while (1) {
    printf("Welcome to the linked list program!\n");
    printf("Insert(1) or Delete(2) or Search(3) or Terminate(0)\n");

    int x;
    scanf("%d", &x);

    if (x == 0) {
      printf("The program has been terminated\n");
      printf("Thankyou for using the program!\n");
      exit(0);
    } else if (x == 1) {
      printf("insert at the last(1) or beginning/start(2)\n");
      int inner_x;
      scanf("%d", &inner_x);
      if (inner_x == 1) {
        printf("enter the data\n");
        int data;
        scanf("%d", &data);
        insert_at_last(start, data);
        printf("The modified list is :\n");
        print_list(start);
      } else if (inner_x == 2) {
        printf("enter the data\n");
        int data;
        scanf("%d", &data);
        printf("enter the location\n");
        int location;
        scanf("%d", &location);
        int err = insert(&start, location, data);
        if (!err) {
          printf("The modified list is :\n");
          print_list(start);
        }
      } else {
        printf("please enter a valid option\n");
        continue;
      }
    } else if (x == 2) {
      printf("delete at the last(1) or beginning/start(2)\n");
      if (info[start] == null) {
        printf("the list contains no node\n");
        continue;
      }
      int inner_x;
      scanf("%d", &inner_x);
      if (inner_x == 1) {
        int err = delete_last_elem(start);
        if (!err) {
          printf("The modified list is :\n");
          print_list(start);
        }
      } else if (inner_x == 2) {
        printf("enter the location\n");
        int location;
        scanf("%d", &location);
        int err = delete (&start, location);
        if (!err) {
          printf("The modified list is :\n");
          print_list(start);
        }
      } else {
        printf("please enter a valid option\n");
        continue;
      }
    } else if (x == 3) {
      int key;
      printf("enter the element you want to search\n");
      scanf("%d", &key);
      int err = search(start, key);
      if (err == -1) {
        printf("the element is not present in the array\n");
      } else {
        printf("the element is at the %dth index\n", search(start, key));
      }
    } else {
      printf("please enter a valid option\n");
      continue;
    }
  }
  return 0;
}
