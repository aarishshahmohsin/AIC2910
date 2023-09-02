#include <iostream>

using namespace std;

int maxi;

int n;

void print_array(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

void delete_at_k(int ar[], int exists[], int *n, int index) {
	for (int i = index; i < *n-1; i++) {
		ar[i] = ar[i+1];
		exists[i] = exists[i+1];
	}
	exists[*n-1] = 0;
	*n = *n-1;
}

void insert_at_k(int ar[], int exists[], int *n, int index, int key) {
	if (index == *n)  {
		ar[index] = key;
		exists[*n] = 1;
		*n = *n + 1;
		return;
	}
	if (exists[index] == 0) {
		ar[index] = key;
		exists[index] = 1;
		if (index > *n) {
			*n = index + 1;
			exists[index] = 1;
		}
		return;
	}
	exists[*n] = 1;
	for (int i = *n-1; i >= index; i--) {
		ar[i+1] = ar[i];
	}
	if (index > *n) {
		*n = index + 1;
	}
	else {
		*n = *n + 1;
	}
	ar[index] = key;
}



int main() {


	cout << "enter the maximum limit of the array size";
	cin >> maxi;
	int ar[maxi];
	int exists[maxi];

	for (int i = 0; i < maxi; i++) {
		exists[i] = 0;
		ar[i] = 0;
	}
	//
	// for (int i = 0; i < maxi; i++) {
	// 	cout << ar[i] << " ";
	// }
	// cout << endl;

	cout << "enter the size of the array" << endl;
	cin >> n;

	if (n <= 0) {
		cout << "enter n > 0" << endl;
		exit(0);
	}

	cout << "enter the elements" << endl;

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		exists[i] = 1;
	}

	cout << "your entered array is" << endl;
	print_array(ar, n);

	while (1) {

		cout << "do you want to exit(0)";
		int temp;
		cin >> temp;
		if (temp == 0) {
			exit(0);
		}

		cout << "insert(1) or delete(2)" << endl;
		int x; cin >> x;

		if (x == 1) {
			// insert
			int k, key;
			cout << "enter the index (0 base indexing)" << endl;
			cin >> k;
			cout << "enter the value" << endl;
			cin >> key;
			insert_at_k(ar, exists, &n, k, key);
			cout << "your output array is" << endl;
			print_array(ar, n);
			print_array(exists, n);
			}
		else if (x == 2) {
			// delete
			int k;
			cout << "enter the index (0 base indexing)" << endl;
			cin >> k;
			if (k > n) {
				cout << "index more than the size" << endl;
				return 0;
			}
			delete_at_k(ar, exists, &n, k);
			cout << "your output array is" << endl;
			print_array(ar, n);
			print_array(exists, n);
			}
		else {
			cout << "please select a number within the options" << endl;
			exit(0);
		}
	}
	
	return 0;
}
