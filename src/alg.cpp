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
    int finish = len - 1;
    while (finish > 0 && arr[len] > value) finish--;
    for (int i = 0; i < len; i++) {
        for (int j = finish; j > i; j--) {
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
                int chto_to = Middle - 1;
                while (chto_to >= LeftSide && arr[chto_to] == key) {
                    count++; chto_to--;
                }
                chto_to = Middle + 1;
                while (chto_to <= RightSide && arr[Mchto_to] == key) {
                    count++; chto_to++;
                }
                break;
            } else if (arr[Middle] < key) {
                LeftSide = Middle + 1;
            } else {
                RightSide = Middle - 1;
            }
        }
    }
    return count;
}
