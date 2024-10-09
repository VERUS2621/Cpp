struct vs class

struct를 이용해서 구조체 선언 -> 별도의 접근제어 지시자 선언X 
-> 모든 변수와 함수는 public 선언

class를 이용해서 클래스 선언 -> 별도의 접근제어 지시자 선언X 
-> 모든 변수와 함수는 private 선언

접근제어 지시자(접근제어 레이블)

public : 어디서든 접근 허용
protect : 상속관계에 놓였있을 때, 유도 클래스에서의 접근 허용
private : 클래스 내(클래스 내에 정의된 함수)에서만 접근 가능

레이블
접근제어 지시자 뒤에는 세미콜론이 아닌 콜론이 붙는데, 이는 접근제어 지시자가 특정위치정보를 알리는
'레이블(라벨)'이기 떄문이다. 우리가 알고 있는 switch문에 사용되는 case도 레이블이기 때문에 콜론이 붙는다.
