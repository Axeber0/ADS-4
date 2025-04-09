// Copyright 2021 NNTU-CS
int countPairs1(const int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
          if ((arr[i] + arr[j]) == value) count++;
      }
  }
  return count;
}
int countPairs2(const int* arr, int len, int value) {
  int count = 0;
  int finish = len - 1;
  while (finish > 0 && arr[finish] > value) finish--;
  for (int i = 0; i < finish; i++) {
      for (int j = finish; j > i; j--) {
          if ((arr[i] + arr[j]) == value) count++;
      }
  }
  return count;
}

int countPairs3(const int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
      int key = value - arr[i];
      int left = i + 1;
      int right = len - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (arr[mid] == key) {
              count++;
              int temp = mid - 1;
              while (temp >= left && arr[temp] == key) {
                  count++;
                  temp--;
              }
              temp = mid + 1;
              while (temp <= right && arr[temp] == key) {
                  count++;
                  temp++;
              }
              break;
          } else if (arr[mid] < key) {
              left = mid + 1;
          } else {
              right = mid - 1;
          }
      }
  }
  return count;
}
