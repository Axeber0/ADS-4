// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  const int* carr = arr;
  int count = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
          if ((carr[i] + carr[j]) == value) count++;
      }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  const int* carr = arr;
  int count = 0;
  int finish = len - 1;
  while (finish > 0 && carr[finish] > value) finish--;
  for (int i = 0; i < finish; i++) {
      for (int j = finish; j > i; j--) {
          if ((carr[i] + carr[j]) == value) count++;
      }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  const int* carr = arr;
  for (int i = 0; i < len - 1; i++) {
      int key = value - carr[i];
      int left = i + 1;
      int right = len - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (carr[mid] == key) {
              count++;
              int temp = mid - 1;
              while (temp >= left && carr[temp] == key) {
                  count++;
                  temp--;
              }
              temp = mid + 1;
              while (temp <= right && carr[temp] == key) {
                  count++;
                  temp++;
              }
              break;
          } else if (carr[mid] < key) {
              left = mid + 1;
          } else {
              right = mid - 1;
          }
      }
  }
  return count;
}
