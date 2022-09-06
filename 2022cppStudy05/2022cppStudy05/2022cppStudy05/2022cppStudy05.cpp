// 2022cppStudy05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class CMyData {
public:
    CMyData() {
        cout << "CMyData()" << endl;
    }

    CMyData(const CMyData &rhs) {   //복사생성자
        cout << "CMyData(const CMyData &)" << endl;
    }

    CMyData(const CMyData&& rhs) {   //이동생성자
        cout << "CMyData(const CMyData &&)" << endl;
    }

    explicit CMyData(int nParam) //변환생성자
        :m_nData(nParam)
    {
        cout << "CMydata(int)" << endl;
    }

    ~CMyData() {
        cout << "~CMyData()" << endl;
    }

    int GetData() const
    {
        return m_nData;
    }

    void SetData(int nParam) {
        m_nData = nParam;
    }

    //연산자 함수
    operator int(void) {
        //허용된 변환
        return m_nData;
    }

    //단순대입 연산자 재정의
    int operator =(int nParam) {
        //m_nData = nParam;   //좋지 못한 코드
        SetData(nParam);
        return nParam;
    }

    CMyData& operator =(const CMyData &rhs) {   //객체 매개변수이므로 참조자지정, 참조자이므로 const 지정
        //m_nData = nParam;   //좋지 못한 코드
        SetData(rhs.GetData());
        return *this;   //복사생성 예방
    }

    CMyData operator+(const CMyData& rhs) {
        return CMyData(this->m_nData + rhs.m_nData);
    }

private:
    int m_nData = 0;

};


int main()
{
    std::cout << "\n**강의내용**\n\n" << std::endl;
    CMyData a;
    CMyData b;
    CMyData c;

    a = b = 5;

    a.SetData(5);
    a.operator=(5);//위와 완전 동일한 코드
    b = 6;

    cout << a.GetData() + b.GetData() << endl;
    cout << a + b << endl;  //허용되는 변환으로 인해 int로 변환

    c = a + b;  //a+b에서 임시객체 생성 c에 대입 후 임시객체 소멸
    
    std::cout << "\n**연습문제**\n\n" << std::endl;
    cout << "1. 대입 연산자 오버로딩 시 주의해야 할 점 두가지는 무엇인지와 그 이유를 답하세요." << endl;
    //r-value가 자기 자신일 경우 동작하도록 해줘야하며, 이것은 문법적으로 문제가 있는 코드가 아니기 때문에 오버로딩시에도 동작하도록 만들어주어야 한다.
    //대입 연산자 함수의 리턴값이 void일 경우 a=b=c와 같은 구문에서 대입오류를 일으킬 수 있으므로 주의해야 한다.
    cout << "2. 각종 대입 연산자들의 적절한 반환 형식은 무엇입니까?" << endl;
    //클래스의 참조자 형식
    cout << "3. 후위식 단항 증가 연산자를 작성하려고 합니다. 적절한 함수 원형을 예로 들어보세요." << endl;
    // int operator++(int) 후위식 단항증가 연산자를 만들 때, 원래의 값을 백업하고 값을 증가시킨 뒤, 백업해둔 값을 리턴하여 구현한다.

    cout << "End of main()" << endl;
    
    
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
