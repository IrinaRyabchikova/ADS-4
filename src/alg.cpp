// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len; i++)
    for(int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value)
        pairs++;
  return pairs;
}

int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = len - 1; i < j; j--)
      if (arr[i] + arr[j] == value)
        pairs++;
  return pairs;
}

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

int countPairs3(int *arr, int len, int value) {
  return lower_bound(arr, len, value + 1) - lower_bound(arr, len, value);
  return 0;
}
