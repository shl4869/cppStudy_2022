// 2022cppStudy01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    std::cout << "**수업내용**\n\n" << std::endl;
    //C
    printf("Hello World!\n");
    
    int a = 10;
    
    int* pnData = (int*)malloc(sizeof(int));
    free(pnData);

    //C++
    std::cout << "Hello World!\n" << std::endl;
    
    int b(10);
    int c(a);   //복사가능
    int (10);

    int* pnNewData = new int;
    delete pnNewData;

    int& rData(b);  //참조자는 일종의 별명이다
    rData=5;    //b의 값이 바뀐다
    std::cout << b << std::endl;    //출력값 5
    //b와 rData는 포인터가 같다

    int&& rNewData = 5; //r-value 참조

    int aaList[3] = { 40, 30, 10 };
    for (auto n: aaList)
        //범위기반 for문: read only, 배열의 전체 요소에 대하여 반복
        std::cout << n << std::endl;

    for (auto& n : aaList) {   //참조자로 read only 해제
        n = 0;
        std::cout << n << std::endl;
    }

    std::cout << "\n**연습문제**\n\n" << std::endl;

    std::cout << "1. 자신의 이름과 나이를 입력받고 \"나의 이름은 홍길동이고, 20살입니다.\"라고 출력하는 프로그램을 작성하세요. \n단, 반드시 std::cout, std::cin을 이용해 작성합니다.\n" << std::endl;
    std::string strName;
    int age(0);
    std::cout << "이름과 나이를 입력하세요.\n" << std::endl;
    std::cin >> strName;
    std::cin >> age;
    std::cout << "나의 이름은 "<<strName<<"이고, "<<age<<"살입니다.\n"<<std::endl;

    std::cout << "2. C++11에서 auto 예약어는 어떤 의미인지 쓰고 코드로 예를 보이세요.\n" << std::endl;
    //auto: 형식지정을 자동으로 해주는 예약어
    auto autoEX(age);
    std::cout << "autoEx: " << autoEX << "\n" << std::endl;

    std::cout << "3. char[12] 배열 메모리를 new 연산자로 동적 할당하고 해제하는 코드 예를 작성하세요.\n" << std::endl;
    char* arrayEX = new char[12];
    delete[] arrayEX;

    std::cout << "4. int에 대한 참조 형식을 매개변수로 받고 두 변수의 값을 교환하는함수를 작성하세요. \n함수 원형은 void Swap(int &a, int &b)입니다.\n" << std::endl;
    int num1(13), num2(7);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
    int& mun1(num1), & mun2(num2);
    Swap(mun1, mun2);
    std::cout << "num1: " << num1 << " num2: " << num2 << "\n" << std::endl;

    std::cout << "6. 다음과 같은 int 배열을 오름차순으로 정렬한 후 화면에 결과를 출력하는 프로그램을 작성하세요.\n단, 화면에 배열 내용을 출력할 때는 반드시 \'범위 기반 for문\'을 사용해야 합니다.\n" << std::endl;
    int aList[5] = { 10,20,30,40,50 };
    //이미 오름차순이므로 정렬 생략, 정렬방법은 자료구조 과제or자료 참고요망
    for (auto n : aList)
        std::cout << n << std::endl;
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
