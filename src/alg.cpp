// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) count++;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    while (arr[len] > value) len--;
    for (int i = 0; i < len; i++) {
        for (int j = len; j > i; j--) {
            if ((arr[i] + arr[j]) == value) count++;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int key = value - arr[i];
        int LeftSide = i + 1;
        int RightSide = len - 1;
        while (LeftSide <= RightSide) {
            int Middle = LeftSide + (RightSide - LeftSide) / 2;
            if (arr[Middle] == key) {
                count++;
                while (Middle - 1 >= LeftSide && arr[Middle - 1] == key) { count++; Middle -= 2; }
                while (Middle + 1 <= RightSide && arr[Middle + 1] == key) { count++; Middle += 2; }
                break;
            }
            else if (arr[Middle] < key) LeftSide = Middle + 1;
            else RightSide = Middle - 1;
        }
    }
    return count;
}
