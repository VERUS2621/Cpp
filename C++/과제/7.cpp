/*
7. 배열의 값을 바꾸는 프로그램 작성
 - void swapArray(int *p, int *q, int size); // p, q는 배열을 가리키고, size는 배열의 크기
 - void printArray(int *p, int size); // p는 배열을 가리키고, size는 배열의 크기
 - swapArray() 함수는 매개 변수로 두 개의 배열과 배열의 크기를 전달받고, 두 배열의 원소를 바꿔치기하며, printArray() 함수는 매개 변수로 전달받은 배열을 화면에 출력
 - main() 함수에 다음 두 정수형 배열을 선언 
     int a[] = { 1,2,3,4,5 };
     int b[] = { 9,8,7,6,5 };
 - swapArray() 함수를 호출하여 배열 a와 b의 데이터를 교환하고 다음 출력과 같이 실행되도록 구현
 - 결과
    배열 a = 1 2 3 4 5
    배열 b = 9 8 7 6 5

    swapArray() 실행...
    배열 a = 9 8 7 6 5
    배열 b = 1 2 3 4 5
*/