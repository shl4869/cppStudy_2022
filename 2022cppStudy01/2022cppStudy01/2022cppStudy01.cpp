// 2022cppStudy01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
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

    int aList[3] = { 40, 30, 10 };
    for (auto n: aList)
        //범위기반 for문: read only, 배열의 전체 요소에 대하여 반복
        std::cout << n << std::endl;

    for (auto& n : aList) {   //참조자로 read only 해제
        n = 0;
        std::cout << n << std::endl;
    }

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
