# Algoritm-Sorting-problem

4가지의 sorting algorithm을 구현해 time complexity를 비교하고자 하였음.

(1) Comparison ALGORITHM

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
