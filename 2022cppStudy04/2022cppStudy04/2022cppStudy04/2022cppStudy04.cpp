﻿// 2022cppStudy04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "\n**연습문제**\n\n" << endl;
    cout << "1. 함수의 매개변수가 기본 형식이 아니라 클래스라면 매개변수 형식은 어떻게 정하는 것이 바람직한지 이유를 답하세요." << endl;
    // 참조자 매개변수로 설정하여 복사생성자가 불려 불필요한 객체가 하나 더 생성되는 것을 막고 상수로 선언하여 원본 객체를 보호한다.
    cout << "2. 복사 생성자 및 단순 대입 연산자를 반드시 정의해야 하는 클래스는 어떤 클래스인지 답하세요." << endl;
    // 클래스에서 포인터 변수를 포함하고 있을 때 DeepCopy가 필요하게 되면서 복사 생성자와 단순 대입 연산자가 필요하다.
    cout << "3. 만일 다음과 같은 코드에서 컴파일 오류가 없었다면 CTestData 클래스는 잠재적인 문제를 가진 것으로 볼 수 있습니다. 그 문제는 무엇이고 어떻게 막을 수 있는지 답하세요." << endl;
    // 주어진 코드에서 TestFunc(5);와 같은 구문은 묵시적 변환으로 인해 변환생성자가 불리고 5와 같은 정수형 상수가 객체화 되어 메모리 사용에 낭비가 일어날 수 있다. 이는 변환생성자를 선언 및 정의할 때 explicit 키워드를 넣어줌으로써 해결할 수 있다.
    cout << "4. 이동시맨틱이 등장한 가장 큰 원인은 무엇으로 볼 수 있는지 답하세요." << endl;
    //여러 대입이나 연산을 할 때 불필요한 임시객체가 두번 만들어지는 것을 막고 곧 소멸한 객체로 인해 순간 메모리 사용량이 튀는 것을 방지하기 위해서 고안되었다.


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
