// cppStudy_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CmyString.h"
#include "MyStringEx.h"

void TestFunc(const CmyString& strParam) {
    cout << strParam << endl;
}

CmyString TestFunc2(void) {
    CmyString strTest("TestFunc2() return");
    cout << strTest << endl;

    return strTest;
}

void TestFunc3(const CmyString& strParam)
{
    cout << strParam[0] << endl;
    cout << strParam[strParam.GetLength() - 1] << endl;
}

int main()
{
    CmyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    //복사생성
    CmyString strNewData(strData);
    cout << strNewData.GetString() << endl;

    //단순 대입 연산자 호출
    strNewData = strTest;
    cout << strNewData.GetString() << endl;

    //변환생성자 및 허용변환
    ::TestFunc(strData);
    ::TestFunc(CmyString("World"));

    // 이름 없는 임시 객체 생성
    TestFunc2();


    //Practice6
    cout << "\n*Practice6" << endl;
    CmyString strLeft("Hello"), strRight("World"), strResult;
    strResult = strLeft + strRight;
    cout << strResult << endl;

    cout << strLeft << endl;
    strLeft += CmyString("World");
    cout << strLeft << endl;

    
    //Practice7
    cout << "\n*Practice7" << endl;
    CmyString strParam("HelloWorld");
    cout << strParam << endl;
    TestFunc3(strParam);


    //Practice8
    cout << "\n*Practice8" << endl;
    strLeft.SetString("Test");
    strRight.SetString("String");

    if (strLeft == strRight)
        cout << "Same" << endl;
    else
        cout << "Different" << endl;

    strLeft = CmyString("String");

    if (strLeft != strRight)
        cout << "Different" << endl;
    else
        cout << "Same" << endl;


    //Practice9
    cout << "\n*Practice9" << endl;
    CMyStringEx strTest2;
    strTest2.SetString("I am a boy.");
    cout << strTest2 << endl;

    int nIndex = strTest2.Find("am");
    cout << "Index: " << nIndex << endl;


    //Practice10
    cout << "\n*Practice10" << endl;
    CMyStringEx strTest3;

    //문자열이 필터링되어 대체되는 경우
    strTest3.SetString("멍멍이아들");
    cout << strTest3 << endl;

    //문자열이 필터링 되지 않는 경우
    strTest3.SetString("Hello");
    cout << strTest3 << endl;


    //Practice11
    cout << "\n*Practice11" << endl;
    CMyStringEx strLeft2("Hello"), strRight2("World");
    cout << strLeft2 + strRight2 << endl;
    

    //Practice12
    cout << "\n*Practice12" << endl;
    CMyStringEx strTest4;
    strTest4.SetString("멍멍2아들");
    cout << strTest4 << endl;

    //Practice13
    cout << "\n*Practice12" << endl;
    CmyString b("World"), c;
    c = "Hello" + b;
    cout << c << endl;


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
