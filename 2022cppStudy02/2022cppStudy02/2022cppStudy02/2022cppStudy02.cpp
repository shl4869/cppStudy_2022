

#include <iostream>
using namespace std;

void TestF(int a, int = 10);


int g_nData = 300;

int Add(int a, int b) {
    return a + b;
}

double Add(double a, double b) {
    return a + b;
}

template <typename T>
T TestFunc(T a) {
    std::cout << a << std::endl;
    return a;
}

inline int AddNew(int a, int b) {
    return a + b;
    //매크로와 같이 함수 call 생략
}

namespace Test {
    int g_nData = 100;
    void TestFunc(void) {
        std::cout << g_nData << std::endl;
    }
    namespace Test2 {
        int g_nData = 200;
    }
}

int main()
{
    std::cout << "**수업내용**\n\n" << std::endl;
    
    //default parameter
    TestF(3);
    TestF(1, 5);

    //overloading
    std::cout << Add(3,4) << std::endl;
    std::cout << Add(3.1, 4.3) << std::endl;

    //template
    std::cout << TestFunc(3) << std::endl;
    std::cout << TestFunc(4.3) << std::endl;
    std::cout << TestFunc("String") << std::endl;

    //namespace
    Test::TestFunc();
    std::cout << Test::g_nData << std::endl;
    std::cout << Test::Test2::g_nData << std::endl;
    std::cout << ::TestFunc(3) << endl;

    //using
    cout << "using namespace std" << endl;

    std::cout << "\n**연습문제**\n\n" << std::endl;

    std::cout << "1. 다음 두 함수 원형에서 잘못된 점은 무엇인지 답하세요." << std::endl;
    // 디폴트 변수의 값을 지정하는 데에 있어 오른쪽부터 지정해야한다는 규칙과 중간에 위치한 변수의 디폴트값 지정을 건너뛸 수 없다는 규칙을 어겼다.
    std::cout << "2. 다음 두 함수는 문법적으로 문제가 없습니다. 하지만 호출하는 코드에서는 문제가 발생할 수 있습니다. \n어떤 문제인지 답하세요." << std::endl;
    // TestFunc(3)과 같이 매개변수를 하나만 넣은 형태로 함수를 호출했을 때 어떤 함수를 호출할지 특정이 되지 않는다.
    std::cout << "3. 함수를 다중정의하는 것보다는 함수 템플릿이더 좋은 코드가 될 가능성이 높습니다. 이유를 답하세요." << std::endl;
    // 함수 템플릿을 사용할 시 함수를 다중정의 했을 때에 발생하는 유지보수 비용이 줄어들기 때문
    std::cout << "4. inline 함수와 매크로의 공통된 장점은 무엇인지 답하세요." << std::endl;
    // 양쪽 모두 컴파일시에 함수 호출로 인한 오버헤드가 나타나지 않아 성능향상을 기대할 수 있다. 
    std::cout << "5. 네임스페이스를 매번 장성하기 싫다면 미리(using)선언을 하는 것이 좋습니다." << std::endl;
    std::cout << "6. 다음 코드의 실행 결과를 작성하세요." << std::endl;
    // 100
    Test::TestFunc();
    return 0;
}

void TestF(int a, int b) {
    std::cout << a << " " << b << std::endl;
}

