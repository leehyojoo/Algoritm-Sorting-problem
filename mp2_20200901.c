#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//인풋 파일 읽고 배열로 반환
int *readInput(char *file_name, int *num) {
  FILE *file = fopen(file_name, "r");
  int *arr;

  if (file == NULL) {
    return NULL;
  }

  fscanf(file, "%d ", num);
  arr = (int *)malloc(sizeof(int) * (*num));

  for (int i = 0; i < (*num); i++) {
    fscanf(file, "%d ", &arr[i]);
  }

  fclose(file);

  return arr;
}

//결과 파일로 저장
void writeFile(char *input_file_name, char *algorithm_index, int input_size,
               double running_time, int *arr) {
  char output_file_name[200] = {0};
  strcat(output_file_name, "result_");
  strcat(output_file_name, algorithm_index);
  strcat(output_file_name, "_");
  strcat(output_file_name, input_file_name);

  FILE *file = fopen(output_file_name, "w");

  fprintf(file, "%s\n", input_file_name);
  fprintf(file, "%s\n", algorithm_index);
  fprintf(file, "%d\n", input_size);
  fprintf(file, "%lf\n", running_time);

  for (int i = 0; i < input_size; i++) {
    fprintf(file, "%d ", arr[i]);
  }

  fclose(file);
}

//삽입 정렬
void insertionSort(int *arr, int l, int r) {
  int key;
  for (int i = l; i < r; i++) {
    key = arr[i + 1];

    int index;
    for (index = i; index >= l; index--) {
      if (arr[index] > key) {
        arr[index + 1] = arr[index];
      } else {
        break;
      }
    }
    arr[index + 1] = key;
  }
}

//배열 원소 위치 바꾸기
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// pivot을 가장 왼쪽값으로 하는 퀵정렬
// 내림차순으로 정렬된 배열에서 좋지 못한 성능
void quickSort(int arr[], int l, int r) {
  if (l >= r)
    return;

  int i = l, j = r;
  int pivot = arr[l];
  do {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (l < j)
    quickSort(arr, l, j);

  if (i < r)
    quickSort(arr, i, r);
}

//힙 생성
void heap(int *arr, int l, int r) {
  for (int i = l; i <= r; i++) {
    int node = i;

    while (node > 0) {
      int parent = (node - 1) / 2;
      if (arr[parent] < arr[node])
        swap(&arr[parent], &arr[node]);
      node = parent;
    }
  }
}

//힙 정렬
void heapSort(int *arr, int l, int r) {
  heap(arr, l, r);

  for (int i = r; i > l; i--) {
    swap(&arr[0], &arr[i]);

    int l = 1, r = 2;
    int node = 0, parent = 0;

    while (1) {
      if (l >= i)
        break;

      if (r >= i)
        node = l;
      else {
        if (arr[l] < arr[r])
          node = r;
        else
          node = l;
      }

      if (arr[node] > arr[parent]) {
        swap(&arr[node], &arr[parent]);
        parent = node;
      } else
        break;

      l = (parent * 2) + 1;
      r = l + 1;
    }
  }
}

// 인트로 정렬에서 사용될 퀵정렬
void _quickSort(int arr[], int l, int r, int depth) {
  if (depth == 0) {
    int size = r - l + 1;

    if (size > 32) {
      heapSort(arr, l, r);
    }
    return;
  }

  int i = l, j = r;
  int pivot = arr[(l + r) / 2];

  do {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (l < j)
    _quickSort(arr, l, j, depth - 1);

  if (i < r)
    _quickSort(arr, i, r, depth - 1);
}

void introSort(int *arr, int num) {
  int limit = 2 * ceil(log2(num));
  if (num <= 32) {
    insertionSort(arr, 0, num - 1);
  } else {
    _quickSort(arr, 0, num - 1, limit);
    insertionSort(arr, 0, num - 1);
  }
}

void main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("The number of execution factors is not correct.\n");
    return;
  }
  char *file_name = argv[1];
  char *alg_num = argv[2];

  int num = 0;
  int *arr = readInput(file_name, &num);
  double start = (double)clock() / CLOCKS_PER_SEC;
  switch (alg_num[0]) {
  case '1':
    insertionSort(arr, 0, num - 1);
    break;
  case '2':
    quickSort(arr, 0, num - 1);
    break;
  case '3':
    heapSort(arr, 0, num - 1);
    break;
  case '4':
    introSort(arr, num);
    break;
  default:
    printf("The algorithm number is not valid.");
    break;
  }
  double end = (double)clock() / CLOCKS_PER_SEC;
  double running_time = end - start;
  writeFile(file_name, alg_num, num, running_time, arr);

  free(arr);
}