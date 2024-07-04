#include <iostream>
using namespace std;


void merge(int arr[], int p, int q, int r) {
 int n1 = q - p + 1;
 int n2 = r - q;
 int L[n1], R[n2];
 for (int i = 0; i < n1; i++)
  L[i] = arr[p + i];
 for (int j = 0; j < n2; j++)
  R[j] = arr[q + 1 + j];
 int i = 0, j = 0, k = p;
 while (i < n1 && j < n2) {
  if (L[i] <= R[j]) {
   arr[k] = L[i];
   i++;
  } else {
   arr[k] = R[j];
   j++;
  }
  k++;
 }
 while (i < n1) {
  arr[k] = L[i];
  i++;
  k++;
 }
 while (j < n2) {
  arr[k] = R[j];
  j++;
  k++;
 }
}

// Merge sort function
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
 }
}

// Print array
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++)
  cout << arr[i] << " ";
 cout << endl;
}

int main() {
 int arr[] = {9, 4, 7, 5, 1, 3, 6, 8, 2};
 int size = sizeof(arr) / sizeof(arr[0]);
 cout << "Original array: ";
 printArray(arr, size);
 mergeSort(arr, 0, size - 1);
 cout << "Sorted array: ";
 printArray(arr, size);
 return 0;
}

