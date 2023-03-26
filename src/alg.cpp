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
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        pairs++;
      }
    }
  }
  return pairs;
}


int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  int l = 0;
  int r = len - 1;
  while (l < r) {
    for (int i = l + 1; i <= r; i++) {
      if (arr[l] + arr[i] == value) {
        pairs++;
      }
    }
    l++;
    for (int j = r - 1; j > l; j--) {
      if (arr[r] + arr[j] == value) {
        pairs++;
      }
    }
    r--;
  }
  return pairs;
}

int countPairs3(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len; i++) {
    int count1 = (lower_bound(arr, len, value - arr[i] + 1)
              - lower_bound(arr, len, value - arr[i]));
    pairs += count1;
    if (arr[i] * 2 == value) {
      pairs--;
    }
  }
  pairs /= 2;
  return pairs;
}
