// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
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
int sort(int* arr, int len) {
int a = 0;
for (int i = 0; i < len; i++) {
  for (int j = 0; j < len - 1; j++) {
  if (arr[j] > arr[j + 1]) {
    a = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = a;
    }
  }
}
return *arr;
}
int countPairs3(int* arr, int len, int value) {
sort(arr, len);
int mid = 0, count = 0;
int left = 0, right = 0;
for (int i = 0; i < len; i++) {
  left = i + 1 , right = len;	
  while (left < right) {
mid = (left + right) / 2;
  if (arr[mid] < (value - arr[i])) {
    left = mid + 1;
} else {
    right = mid;
  }
}
while (arr[left] == (value - arr[i])) {
  count+=1;
  left+=1;
  }
}
return count;
}
