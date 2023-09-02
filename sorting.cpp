/*
 @author: AARISH SHAH MOHSIN
 @faculty_no: 22AIB126
 @enrol_no: GM1674
 @class: A2AI
*/

#include <iostream>

using namespace std;

void swap_in_array(int ar[], int f, int s) {
	int temp = ar[f];
	ar[f] = ar[s];
	ar[s] = temp;
}

void bubble_sort(int ar[], int n) {
	for (int i = 0; i < n-1; i++) {
		int swapped = 0;
		for (int j = 0; j < n-i-1; j++) {
			if (ar[j] > ar[j+1]) {
				swap_in_array(ar, j, j+1);
				swapped = 1;
			}
		}
		if (!swapped) break;
	}
}

void selection_sort(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		int min_ind = i;
		for (int j = i; j < n; j++) {
			if (ar[j] < ar[min_ind]) min_ind = j;
		}
		swap_in_array(ar, i, min_ind);
	}
}

void print_array(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

int main() {

	int n;
	cin >> n;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	// bubble_sort(ar, n);
	// selection_sort(ar, n);
	// insertion_sort(ar, n);
	print_array(ar, n);

	return 0;
}
