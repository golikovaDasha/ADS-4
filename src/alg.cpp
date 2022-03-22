// Copyright 2021 NNTU-CS
void sort(int* arr, int len) {
int j = 0, zamen = 0;
for (int i = 0; i < len; i++) {
  j = i;
for (int k = i; k < len; k++) {
  if (arr[j] > arr[k]) {
    j = k;
  }
}
zamen = arr[i];
arr[i] = arr[j];
arr[j] = zamen;
  }
}
int countPairs1(int* arr, int len, int value) {
sort(arr, len);
int count = 0;
for (int i = 0; i < len - 1; i++) {
  for (int j = i + 1; j < len; j++) {
    if ((arr[i] + arr[j]) == value) {
    count += 1;
    }
  }
}
return count;
}
int countPairs2(int* arr, int len, int value) {
sort(arr, len);
int count = 0;
for (int i = 0; i < len - 1; i++) {
  if (arr[i] < value) {
    for (int j = len - 1; j > i; j--) {
      if (arr[j] < value && ((arr[i] + arr[j]) == value)) {
        count += 1;
      }
    }
  }
}
return count;
}
int countPairs3(int* arr, int len, int value) {
sort(arr, len);
int count = 0;
for (int i = 0; i < (len - 1); i++) {
  int left = i, right = len;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if ((arr[i] + arr[mid]) == value) {
      count++;
      int j = mid + 1;
      while ((arr[i] + arr[j]) == value && j < right) {
        count++;
        j++;
      }
      j = mid - 1;
      while ((arr[i] + arr[j]) == value && j > left) {
        count++;
        j--;
      }
      break;
      }
      if ((arr[i] + arr[mid])> value) {
        right = mid;
      } else {
        left = mid;
    }
  }
}
return count;
}
