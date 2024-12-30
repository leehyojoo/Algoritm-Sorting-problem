# 정렬 알고리즘 시간 복잡도 비교

이 프로젝트는 삽입 정렬, 퀵 정렬, 힙 정렬, 그리고 인트로 정렬의 시간 복잡도를 비교하기 위해 설계 되었음.
각 알고리즘을 구현하고 다양한 데이터셋에 대해 실행하여 성능을 관찰하고자 함.

## 프로젝트 개요

이 프로젝트는 다음의 정렬 알고리즘들을 구현하고 성능을 비교:

- **삽입 정렬 (Insertion Sort)**
- **퀵 정렬 (Quick Sort)**
- **힙 정렬 (Heap Sort)**
- **인트로 정렬 (Intro Sort)**

목표는 각 데이터셋 크기 및 분포에 따른 알고리즘의 시간 복잡도를 관찰하고 기록하는 것임.

## Sorting Algorithm

Algorithm1 - Insertion Sort
Algorithm2 – quick sort
Algorithm3 – Heap Sort
Algorithm4 – Intro Sort

insertionSort 함수:

삽입 정렬 알고리즘을 구현한 함수
배열의 특정 범위를 정렬

quickSort 함수:

퀵 정렬 알고리즘을 구현한 함수
배열의 특정 범위를 퀵 정렬
배열의 가장 왼쪽 값을 pivot으로 선택

heapSort 함수:

힙 정렬 알고리즘을 구현한 함수
배열의 특정 범위를 힙 정렬

_quick sort 함수:

인트로 정렬에 사용되는 퀵 정렬 함수
배열의 특정 범위를 퀵 정렬
깊이(depth)가 0이 되면 배열 크기에 따라 힙 정렬을 수행하고 종료

introSort 함수:

인트로 정렬 알고리즘을 구현한 함수
배열을 먼저 퀵 정렬하고, 그 후에 삽입 정렬을 수행
배열 크기가 작은 경우에는 직접 삽입 정렬을 수행
