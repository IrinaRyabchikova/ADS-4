// Copyright 2021 NNTU-CS
int lower_bound(int *arr, int size, int value) {
  int left = 0, right = size;
  if (arr[0] >= value) {
    return 0;
  }
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (arr[mid] >= value) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}

int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len; i++) {
    for(int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        pairs++;
      }
    }
  }
  return pairs;
}

int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        pairs++;
      }
    }
  }
  return pairs;
}

int countPairs3(int *arr, int len, int value) {
  int pairs = 0, i = 0;
  while (arr[i] < value - arr[i]) {
    pairs += (lower_bound(arr, len, arr[i] + 1) - lower_bound(arr, len, arr[i])) * (lower_bound(arr, len, value - arr[i] + 1) - lower_bound(arr, len, value - arr[i]));
    i = lower_bound(arr, len, arr[i] + 1);
  }
  return pairs;
}
