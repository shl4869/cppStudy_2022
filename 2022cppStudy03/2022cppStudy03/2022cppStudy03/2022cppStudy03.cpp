// 2022cppStudy03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CmyString.h"
using namespace std;

class CRef {
public:
    CRef(int &rParam) {
        m_nData = rParam;
    }

    int GetData(void) {
        return m_nData;
    }

private:
    int m_nData;
};

void testPR2(const CmyString& param) {
    cout << param.GetString() << endl;
}
int main()
{
    std::cout << "\n**연습문제**\n\n" << std::endl;

    std::cout << "1. 클래스 접근제어 지시자 중에서 private이 의미하는 것은 무엇인지 답하세요." << std::endl;
    //private은 기본 지시자로, 외부 접근 뿐만 아니라 파생 클래스로부터의 접근까지 모두 차단한다.
    std::cout << "2. 클래스 인스턴스가 생성될 때 자동으로호출되는 함수는 무엇이며, 함수 원형의 가장 큰 외형상 특징은 무엇인지 답하세요." << std::endl;
    //생성자는 외형상 매개변수와 반환형이 보이지 않는다.
    std::cout << "3. 다음 코드에서 m_nData(nParam)이 속한 부분을 무엇이라 부르는지 답하세요." << std::endl;
    //생성자 초기화 목록
    std::cout << "4. 다음 코드에서 잘못된 점은 무엇이며 문법 오류를 피하려면 어떻게 수정해야 하는지 답하세요." << std::endl;
    //&m_nData;가 의미하는 바는 참조자이고, 참조자는 선언과 동시에 정의해주어야 한다. 따라서, m_nData는 일반 정수형으로 선언하는것이 옳다.
    std::cout << "5. 메서드 함수 내부에서 실제 클래스 인스턴스의 주소를 가리키는 포인터는 무엇인지 탑하세요." << std::endl;
    //this
    std::cout << "6. 상수형 메서드에서 할 수 없는 일은 무엇인지 탑하세요." << std::endl;
    //멤버 변수의 쓰기 권한이 없어진다.
    std::cout << "7. 정적 멤버에서는 '이것'을 사용할 수 없습니다. 이것은 무엇입니까?" << std::endl;
    //this 포인터
 
    std::cout << "\n**실습과제**\n" << std::endl;
    CmyString strData;
    strData.SetString("Hello!");
    cout << strData.GetString() << endl;
    strData.SetString("World!");
    cout << strData.GetString() << endl;
    
    //practice2
    strData.SetString("Practice2");
    testPR2(strData);

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
