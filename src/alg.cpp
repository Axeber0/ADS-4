// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i; j < len; j++) {
          if (i == j) continue;
          if ((arr[i] + arr[j]) == value) count++;
      }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  while (arr[len] > value) len--;
  for (int i = 0; i < len; i++) {
      for (int j = len; j > i; j--) {
          if ((arr[i] + arr[j]) == value) count++;
      }
  }   
  return count;
}

int binar(int* arr, int len, int value) {
  int left = 0;
  int right = len;

  while (left <= right) {
      int mid = left + (right - left) / 2; 

      if (arr[mid] == value) {
          return mid; 
      }
      else if (arr[mid] < value) {
          left = mid + 1; 
      }
      else {
          right = mid - 1; 
      }
  }

  return -1;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
      if (arr[i] + arr[binar(arr, len, (value - arr[i]))] == value) count++;
  }
  return count/2;
}
