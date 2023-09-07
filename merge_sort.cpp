#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<vector<int>>> visual(1000);
int level = 0;

void print_arr(int ar[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      printf("%d]\n", ar[i]);
    } else {
      printf("%d, ", ar[i]);
    }
  }
}

vector<int> conv(int ar[], int n) {
  vector<int> out;
  for (int i = 0; i < n; i++) {
    out.push_back(ar[i]);
  }
  return out;
}

void print_vec(vector<int> ar) {
  cout << "[";
  for (int i = 0; i < ar.size(); i++) {
    cout << ar[i] << " ";
  }
  cout << "]";
}

void merge(int ar[], int n, int l1, int l2, int r1, int r2) {

  int n1 = l2 - l1 + 1;
  int n2 = r2 - l2;
  int left_arr[n1], right_arr[n2];

  for (int i = 0; i < n1; i++) {
    left_arr[i] = ar[l1 + i];
  }
  for (int i = 0; i < n2; i++) {
    right_arr[i] = ar[r1 + i];
  }

  int i = 0, j = 0, k = l1;
  while (i < n1 && j < n2) {
    if (left_arr[i] <= right_arr[j]) {
      ar[k] = left_arr[i];
      i++;
    } else {
      ar[k] = right_arr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    ar[k] = left_arr[i];
    i++;
    k++;
  }

  while (j < n2) {
    ar[k] = right_arr[j];
    j++;
    k++;
  }

  int size = max(sizeof(left_arr), sizeof(right_arr)) / sizeof(int);
  visual[size].push_back(conv(left_arr, n1));
  visual[size].push_back(conv(right_arr, n2));
  level = size;
}

void merge_sort(int ar[], int n, int l, int r) {
  if (r <= l) {
    return;
  }
  int m = (long long)(l + r) / 2LL;
  merge_sort(ar, n, l, m);

  merge_sort(ar, n, m + 1, r);

  merge(ar, n, l, m, m + 1, r);
}

int main() {
  int n;

  printf("enter the no of elements\n");
  scanf("%d", &n);

  int ar[n];

  printf("enter the elements\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }

  printf("Entered Array : ");
  print_arr(ar, n);
  merge_sort(ar, n, 0, n - 1);
  printf("Sorted Array : ");
  print_arr(ar, n);

  int k = 0;
  for (auto i : (visual)) {
    if (i.size() > 0) {
      for (auto j : i) {
        print_vec(j);
        printf(" ");
      }
      printf("\n");
      k++;
    }
  }
  vector<int> x = conv(ar, n);
  print_vec(x);
  cout << endl;
  return 0;
}
