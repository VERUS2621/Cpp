## C언어 복습

기본 구조 - 프로그램은 main 에서 시작..끝
```c
#include <stdio.h>
int main(void) { // 함수로 입력과 리턴값이 필요. 반환값 없으면 void
  int a = 10, b = 20;
  int c = a + b;
  printf("%d + %d = %d", a, b, c);
  return 0; 
}
```

```c
int main(int argc, char **argv) 
// main 기본형태. argc: 매개변수 개수, argv: 매개변수 배열
> program arg1 arg2 // 실행시 argc = 3, argv = [‘program’,’arg1’,’arg2’] 가 들어감.
```


### 주석 - //, /* */
```c
// 한 줄 주석
/* 여려 줄
주석*/
```


### 변수 - 정수형, 실수형, 상수, sizeof
```c
정수형 (변수저장공간(N바이트)):
 char:(1B), short:(2B), int:(4B:환경에 따라 다를 수 있음), long:(4B), long long:(8B)
 char c = 65; c =  'A'; // 같은 결과, 아스키코드(문자코드) 값으로 넣을 수 있음

실수형 (N바이트, 유효숫자(소수점자리수)):
 float:(4B,7), double:(8B,15), long double:(8B이상,15이상)

unsigned int = 10; //unsigned 를 붙이면 양수만 사용해서 두배까지 대입가능
const int tax = 10: // const 상수(변경불가)로 선언됨. 초기값 필수
sizeof(long) // 4, 변수/객체 크기 리턴
size_t //부호없는 정수형(unsingend int, 크기는 컴파일러마다 다름), 
size_t strlen(str); // size_t는 sizeof, 문자열길이, 파일크기 등의 값으로 사용
```


### 문자열 - 문자열은 "문자열"(쌍따옴표만). 문자값(아스키값)은 'A'(홑따옴표)
```c
char str[80] = "apple"; // 배열 문자열 초기화.. 남는 요소는 0(null, \0)로 채워짐.
```

### 초기화 후 문자열 대입: ++배열 str = "새로운문자열"; 안됨++
```c
 #include <string.h>
 strcpy(str, "banana"); //str 문자열에 banana 문자열 복사해서 대입.
// str = "banana"; str(변수가 아닌 배열주소임)에 직접 대입 불가 
```
```c
**문자열 연산함수**:
strcpy(s1, s2); //s1에 복사후 null 추가
strncpy(s1, s2, n); // n:복사할 문자수, s1에 복사후 null 추가 안함.
strcat(s1, s2);  //s1에 연결. null 추가.
strncat(s1, s2, n);  //s1에 n자만큼 연결. null 추가. 
strlen(str); // 문자열 길이 리턴
strcmp(s1, s2); // 사전순으로 같으면 0, s1이 크면 1 작으면 -1
strncmp(s1, s2, n); // 지정한 크기만큼 비교

문자열 입출력시 주의:
char str[80];
scanf("%s", str); // 하나의 단어만 입력. 공백문자 있으면 그 전까지만 입력
gets(str); // 한 줄 입력
puts(str); // 한 줄 출력
```


### 입/출력 공통 - 포맷, 제어, 표준스트림
```c
포맷문자:
 %c (char) %d (int) %hd (short) %ld (long), %lld (long long), %lu (unsigned long) 
 %lf (double), %Lf (long double) %u (unsigned 정수형 모두) %p (포인터)

제어문자:
 \n(줄바꿈) \t(탭) \r(줄앞) \b(백스페이스) \a(알럿/벨소리)

 printf("%c %s %d %f\n", 'A', "abc", 10, 10.5);

표준스트림:
 stdin : 표준입력스트림: 키보드
 stdout: 표준출력스트림: 모니터
 stderr: 표준에러스트림: 모니터
 putc('A', stdout); // 표준출력스트림(화면)에 출력
```

### 출력 - printf, puts, fputs, putchar, putc
```c
printf("문자열: %s, 정수: %d, 실수: %f 줄바꿈제어문자\n", "문자열", 10, 10.5);
int puts(const char *str) //출력후 줄바꿈
int fputs(const char *str, FILE *stream) //출력후 줄바꿈 안함 //stdout 사용하면 화면출력.
// 아래는 간단한 문자출력함수로 간단해서 빠름 
int putchar(int); // putc(int,stdout) 과 같음. 출력할 문자를 넣으면 출력  
```

### 입력 - scanf, getchar, getc, gets, fgets
입력 숫자
```c
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
// scanf 같은 메모리접근 함수 사용시 보안 에러가 나오면 위 코드를 넣어 경고를 해제시킨다.
int a;
scanf("%d", &a); // 입력포맷과 입력받을 변수의 주소(&변수명)를 넣어준다)

// 여러개의 값을 입력받기. 변수포맷과 변수주소를 원하는 만큼  넣어준다.
int a; float b;
scanf("%d%f", &a, &b); // 정수와 소수를 입력받음. 구분은 [공백, 탭, 엔터] 가능.

scanf("%c%c", &c1, &c2); //ab [엔터] 면 c1='a',c2='b' 입력됨
scanf("%d %d", &n1, &n2); // 화이트스페이스(공백,탭,엔터)로 구분해서 각 변수에 입력됨
scanf(" %c %c", &c1, &c2); //문자도 화이트스페이스 구분해서 받음.
```

### 입력안내 문자+문자열 입력받기:
```c
 char name[20]; // 문자열 입력을 위한 배열 
 printf("이름: "); scanf("%s", name); // 배열이름이 주소이므로 &생략
 // *주의:scanf 는 공백이 들어가 있으면 그 전까지만 입력을 받습니다. 

char str[80]; // 문자열은 일반적으로 배열로 받음.
fgets(str, sizeof(str), stdin); // 배열을 넘어서지 않도록 지정한 크기까지만 받음. stdin(표준입력)
 // fgets 은 문자열 끝에  \n 값을 저장하므로 str[strlen(str) - 1] = ‘\0’; 제거해 줄 수 있다.

gets(str); // 공백 상관없이 한줄을 다 받을 수 있음
int getchar(void); // getc(stdin) 와 같음. 입력한 문자 반환
```

### 연산자
```c
관계연산자:
 > , >=, <, <=, ==, !=
논리연산자:
 && (AND), || (OR), ! (NOT)
비트연산자:
 &, |, ^, ~, <<, >> (쉬프트연산자)
증감연산자:
 i++ (나중에 증가) ++i (우선증가) i– (나중에 감소) –i(우선감소)
사칙연산자:
 +, -, *, /, %(나머지)

형변환:
 float a = 10.1;
 int b = (int)a; // 강제로 float 값이 int 값이 되어 10 이 된다.
자동형변환  : 연산시 다른 자료형이면 큰 자료형으로 자동으로 일치시킨다.
 
sizeof 연산자 : 자료형의 크기(바이트)를 리턴
double d=10.1; sizeof(d); // 8 리턴. 연산자 이므로 sizeof d; 처럼 괄호없이 사용해도 됨.

복합연산자:
 +=, -=, *=, /=, %=

조건연산자(3항연산자):
 (a > b) ? a : b;
```


### 선택문 - if, switch
```c
if (a == 1) { 
} else if (a == 2) { //생략가능
} else { //생략가능
}

switch (k) {
  case 1:  break; // switch 문 끝냄
  case 2:  //break 없으면 다음 case 도 실행
  default:  //앞쪽 조건에서 break 되지 않았으면 실행. 생략가능
}
```

### 반복문 - for, while, do~while
```c
for (i = 0; i < 10; i++) { // 10번 루프
  if (i == 5) continue; //뒷부분 실행없이 루프 초기로 점프
  if (i == 8) break; // 뒷부분 실행없이 루프를 한겹 빠져나감 
}

int n = 9;
while (n > 0) { // 조건식이 참일 경우 계속
  n--;
}

do { // 무조건 한번이상 실행됨
  n--;
} while (n > 0); //조건식이 참을 경우 계속
```

### 함수 - 매개변수, void, 재귀호출
```c
int sum(int a, int b) { // 매개변수(입력값)나 리턴값이 없으면 void 로 표시. void fnc(void) { return; }
  return a + b;
}

재귀호출 함수: 자신의 함수를 콜하는 함수
int factorial(int num) {
  if (num <= 1) return 1; // 재귀호출 무한 루프 방지를 위해 빠져나오는 조건 필수.
  return num * factorial(num - 1); // 자신을 콜한다.
}
```

### 배열 - 초기화, 크기계산
```c
int a[3] = {1, 2, 3}; // 각 배열을 값으로 초기화
int a[3] = {1}; // 처음값은 1, 나머지는 0으로 초기화

int sz = sizeof(a) / sizeof(a[0]); // sizeof 를 이용한 임의의 배열크기 계산
```

### 다차원배열 - 2차원, 3차원
```c
2차원: 행x열
3차원: 면x행x열
int a2[2][3] = { //2행x3열 배열
 {1, 2, 3},
 {4, 5, 6}
}; // 초기화

int a2[][3] = {1, 2, 3, 4, 5, 6} // 행을 생략하거나, 초기값을 일렬로 넣어도 됨.
int a2[2][3] = {1} // 설정값으로 초기화, 설정없는 나머지는 0으로 초기화됨.

int r = sizeof(a2) / sizeof(a2[0]); // 2차원배열 행의 수
int c = sizeof(a2[0]) / sizeof(a2[0][0]); //2차원배열 열의 수
```

## 포인터 - 주소를 저장하는 변수

```c
int *pn, *pn2; //여러개 선언시 문법
*pn : *(포인터연산자(간접참조연산자)) pn(포인터)
int n = 10; pn = &n; // *pn == n == 10

포인터에 const 사용시 유의점: 상수문자열 사용시 const 포인터 사용(값 변경방지).
int a = 10, b = 20;
const int *p = &a;
p = &b; // 주소 참조는 가능
*p = 30; // const 이므로 값을 변경하는 건 불가능. 

printf("%p", &a); // 주소 출력시 p 사용
```

주소와 포인터 차이:
 주소: 변수에 할당된 메모리의 시작 주소. **변수의 주소는 변하지 않음**.
 포인터: ++주소값을 저장++하는 **별도의 메모리 공간(변수)**. 가르키는 포인터주소는 대입으로  변경될 수 있음.

포인터 대입 규칙:
 **선언된 포인터와 같은 자료형일 경우에만 대입가능**
 형변환을 하면 가능

배열과 포인터:
 int a[3]; // 배열명은 배열 첫원소의 주소, 즉 포인터와 같다. 즉, *(a + 1) 는 a[1] 과 같다.
 포인터에서 덧셈이나 뺄셈은 포인터 자료형크기 만큼씩 증감.

배열명과 포인터 차이:
 sizeof 연산결과가 다르다. **배열명은 배열 전체크기**, **포인터는 4바이트**(포인터 하나의 크기)
 포인터는 값을 바꿀 수 있지만, 배열명은 상수이며 변경불가

### 변수 스코프(유효범위) - 지역, 전역, static, 레지스터
```c
int cnt = 0; //전역변수 
int sum(a, b) { // 매개변수 a, b 도 지역변수
  static int total; //정적지역변수, 초기화값이 없으면 0으로 초기화 됨.
  int c; //지역변수
  c = a + b;
  total += c; //total 은 정적변수라 함수가 다시 실행되도 최종값을 저장하고 있음.
  cnt++; //전역변수라 최종 값을 계속 유지.
  return c;
}
int main() {
  sum(1,1); sum(2,2); //sum 함수 2번 실행
}
// 실행 후 전역변수 cnt==2 (2회카운트), 정적변수 total==6 (1+1+2+2) 이 됨.
```

전역변수:
 -함수 밖에서 선언된 변수. 여러 함수내에서 공유해서 사용가능.

지역변수:
 -블럭내에서만 사용되고 없어짐.
 -auto 변수와 동의어. auto int c; 처럼 auto 가 생략될 수 있음.
 -함수내에 같은 이름이 두개면 가까운 블럭내 변수를 사용.

정적지역변수:
 -static 예약어 사용. 지역변수지만 함수가 끝나도 메모리에 값이 유지된다.

레지스터 변수:
 register int i=0;
 -메모리가 아닌 CPU 레지스터 메모리를 사용해 속도가 빠름
 -임시로 사용되므로 전역변수는 안됨.
 -램이 아니므로 주소 정보가 없음.
 -실제 레지스터 사용여부는 컴파일러가 결정함.

### 포인터배열 - 배열에 포인터값으로 배열을 유지
```c
char *ps[2] = {"apple", "banana"}; // 문자열의 위치주소(각 문자열 저장공간 불연속적, 크기도 각 문자열 크기)를 가지고 있음.
char as[2][8] = {"apple", "bannna"}; // 문자열 자체의 배열공간(연속적위치)을 가짐.
포인터: 변수의 메모리 주소를 가지고 있는 변수
이중 포인터 : 포인터의 주소를 저장하는 포인터, 즉 포인터의 주소를 가진 변수
int a = 10;
int *p = &a; // 포인터 p에 변수 a의 주소를 저장
int **pp = &p; // 이중포인터에 포인터의 주소를 저장
// a == 10 == *p == **pp // 모두 10을 가르킴
int ***ppp; // 이중 이상의 다중포인터도 가능하지만 가독성 떨어짐

이중포인터를 이용한 포인터교환:
void swap_s(char **pp1, char **pp2) {
  char *p = *pp1; *pp1 = *pp2; *pp2 = *p;
}
char *s1 = "s1", char $s2 = "s2";
swap_s(&s1, &s2); // 포인터 주소만 바뀌어서 스왑됨.

배열주소: a, &a 는 연산시 다르게 처리.
 char a[5]; // a는 배열의 주소, &a 도 배열의 주소
 sizeof(a) // == 5(배열전체 크기). (a+1) 은 1바이트 다음주소 -> 첫 번째 요소에서 한 바이트 다음 주소
  // (&a + 1)은 char형*5 == 5바이트 다음 주소를 가르킴
  // 배열 전체의 끝 주소로부터 배열 크기만큼 떨어진 주소
```

### 함수포인터 - 함수의 주소를 저장할 수 있는 포인터, 함수의 형태와 같게 선언해야 함
```c
int sum(int a, int b) { return a + b; } 
int mul(int a, int b) { return a * b; }
int (*myf)(int, int); // 대입할 함수(위쪽 예)와 같은 형태로 선언. *주의-() 없으면 포인터리턴함수로 됨.
myf = sum; myf(1,1); // 형태가 같은 함수(위에 sum, sub)를 대입해서 실행가능.
```

### void 포인터 - 자료형이 정해지지 않은(가변적인) 포인터
```c
int a = 10; double b = 10.5;
void *vp;
vp = &a; vp = &b; // 모든 변수형태 대입가능. 단 자료형이 미정이므로 간접참조나 증가 포인터 연산 불가능.
printf("a: %d", *(int *)vp); // 형변환(int *)을 통해 참조나 포인터 연산 가능 
```

### 메모리 동적할당 - malloc, free, calloc, realloc
```c
#include <stdlib.h>
void *malloc(unsigned int size); // 메모리할당. 리턴 자료형이 가변적이므로 void* 형. 형변환해서 사용.
void free(void *p); // 메모리 해제 함수

int *m = (int *)malloc(sizeof(int)*10);
if(m == NULL) { printf("메모리 부족"); exit(1); }
free(m);

void *calloc(unsigned int size, unsigned int size_ty);  //주어진 타입의 갯수만큼 메모리 할당후 초기화.
void *realloc(void *p, unsigned int size); // 주어진 크기로 재할당

int *m = (int *)calloc(10, sizeof(int)); //초기화되므로 초기화 필요할 때 사용하면 좋음.
m = (int *)realloc(m, 20*sizeof(int)); // 재할당시 주소가 바뀔수 있으니 리턴값을 다시 받아야 함.
free(m); // calloc 할당도 free 로 해제 
```
프로그램 실행중 메모리 구조:
 [ 코드영역   ] : 실행파일 영역
 [ 스택       ] : 지역변수 영역
 [ 기타데이터 ] : 전역, 정적변수 영역
 [ 힙         ] : 동적할당 영역

### 구조체 - struct

```c
struct person { // student 이름의 구조체 형선언
  int age;
  char name[20];
};

struct person p1; // 구조체 변수 선언
p1.age = 15; // 구조체 멤버변수에 대입

구조체의 크기는 멤버변수 크기의 합이 아니라 정렬하기 쉽게 일정 크기로 빈메모리를 추가해서 정렬된다.

struct person p2 = { 16, "홍길동" }, p3 = { 14, "홍길순"}; //선언+초기화
struct person {int age; char name[20]; } p1 = { 17, "홍길동" } //형선언+변수선언+초기화 동시
struct person fnc(struct person p1); //함수 매개변수, 리턴값에 구조체 사용 예
struct person *pp1 = &p1; // 구조체 포인터에 p1주소대입
(*pp1).age = 19; pp1 -> age = 19; // (*pp1) 또는 ->(간접멤버 연산자)로 접근.
```

### 공용체 - union
구조체와 문법은 같음. 
 : 멤버변수들이 하나의 저장공간을 같이 사용. **제일 큰 자료형의 크기로 할당**
 : **같은 공간을 사용**하므로 어떤 멤버에 쓰던 영향을 줌.
 : **데이터가 어떤 형태로 들어올지 모를 경우**의 자료형을 사용할 때 사용.
```c 
union u {
  char a;
  int b;
}; 
```
### 열거형 - 변수에 저장할 수 있는 정수값을 기호로 정의하여 나열
```c
enum play_st { STOP, PLAY = 3, PAUSE }; 
// 열거형 선언. 0부터 이름을 붙임. 값을 넣어주면, 다음 것은 그것보다 1큰값.
enum play_st PlaySt; PlaySt = PLAY; 
//enum 을 변수처럼 선언해서 값을 대입.
```
### 파일 입출력 - fopen, fgetc, fputc, fgets, fputs, fscanf, fprintf
NULL, EOF 의미
```c
#define NULL ((void *)0) // NULL 값. 파일 열기 실패.
#defune EOF (-1) // End Of File 파일끝 

#include <stdio.h>
int main(void) {
  FILE *fp; // 파일포인터
  int ch;
  if ((fp = fopen("a.txt", "r")) == NULL) { return 1; } // NULL 이면 오픈 실패
  while (1) {
    ch = fgetc(fp); // 한글자씩 읽어옴
    if (ch == EOF) break; // 파일 끝이면 읽기에서 빠져나옴
    putchar(ch); // 읽은 문자를 화면에 출력
  }
  fclose(fp); // 파일 닫음
  return 0;
}

FILE* fopen(const char* fname, const char* mode); //파일 오픈
 // 파일열기 모드: r(읽기) w(쓰기) a(추가쓰기) +b(바이너리파일) +(읽고쓰기)
char *fgets(char *str, int size, FILE *fp); // 한줄씩읽음
int fputs(const char *str, FILE *fp); // 한출씩 출력
int fscanf(FILE *fp, "%d", &v); //파일에서 변수로 변환해서 읽음
int fprintf(FILE *fp, "%d", v); // 변수를 파일에 변환해서 출력

//일반적으로 바이너리 파일 입출력은 fread, fwrite 함수 사용
typedef struct { int left, top, right, bottom; } RECT;
int main() {
  FILE *fp;
  RECT rect = {10, 10, 20, 20};
  if ((fp = fopen("rect.dat", "wb+")) == NULL) { return 0; }
  fread(&rect, sizeof(RECT), 1, fp); //RECT 크기만큼 1번 읽어서 rect에 넣는다.
  // size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
  fwrie(&rect, sizeof(RECT), 1, fp); //RECT 크기만큼 1번 rect에 있는 내용을 넣는다.
  // size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
  fclose(fp);
  return 0;
}
```
### 자료형 재정의 - typedef
```c
typedef struct person Person; // struct person 을 Person 으로 재정의해 사용할 수 있다.
typedef unsigned int size_t; //unsigned int 를 size_t 로 재정의. 자료형들을 모두 재정의 가능.
```
### 매크로 - #define

#### #define 매크로명 치환될내용
```c
#define MYMAX 99 // 매크로명
#define SUM(a, b) ((a) +(b))  // 매크로 함수
```