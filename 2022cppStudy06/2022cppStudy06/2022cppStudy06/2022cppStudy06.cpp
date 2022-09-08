// 2022cppStudy06.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class CTest
{
public:
    CTest() //default
    {
        cout << "CTest()" << endl;
    }

    void TestFunc(void) {
        cout << "CTest::TestFunc()" << endl;
    }
};

class CTestEx : public CTest
{
public:
    CTestEx() //default
    {
        cout << "CTestEx()" << endl;
    }

    //재정의
    void TestFunc(void) {
        cout << "CTestEx::TestFunc()" << endl;
    }
};

int main()
{
    std::cout << "\n**강의내용**\n\n" << std::endl;
    CTest a;
    a.TestFunc();

    CTestEx b;  //CTest() call before CTestEx() call
    b.TestFunc();   //the one that has been overrided

    CTest& c = b;
    c.TestFunc();   //일반함수는 접근 형식 따름: CTest::TestFunc() call

    std::cout << "\n**연습문제**\n\n" << std::endl;
    std::cout << "1. 파생 클래스에서 일반 매서드를 재정의했다고 가정하겠습니다.\n만일, 파생 형식 인스턴스를 기본 형식에 대한 포인터로 포인팅하고 호출한다면 기본 형식과 파생 형식 중 어느 클래스의 매서드가 호출될까요?" << std::endl;
    //일반함수는 접근형식에 따르므로 접근형식인 파생형식의 메서드가 호출된다.
    std::cout << "2. A는 B의, B는 C의 기본 클래스일 때 C 클래스의 인스턴스를 선언한다고 가정하면 가장 먼저 '실행' 되는 생성자는 어느 클래스의 생성자입니까?" << std::endl;
    //생성자의 call 순서는 가장 밑의 파생클래스부터 기본클래스까지 올라가지만 실행 순서는 반대이다. 따라서 가장 기본클래스인 A의 생성자가 가장 먼저 실행된다.


    return 0;
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
