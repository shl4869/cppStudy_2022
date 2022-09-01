#include "CmyString.h"
#include <cstring>
#include <iostream>

//생성자
CmyString::CmyString()
	:m_pszData(nullptr),m_nlength(0)
{

}

//복사 생성자
CmyString::CmyString(const CmyString& rhs) 
{
	//정수형 복사
	m_nlength = rhs.m_nlength;

	//문자열 복사
	m_pszData = new char[m_nlength + 1];
	this->SetString(rhs.GetString());
}

//변환생성자
explicit CmyString::CmyString(const char* myStr)
	:m_pszData(nullptr), m_nlength(0)
{
	this->SetString(m_pszData);
}

//이동생성자
CmyString::CmyString(CmyString&& rhs)
	:m_pszData(nullptr), m_nlength(0)
{
	cout << "CmyString 이동생성자 호출" << endl;

	//어차피 원본이 곧 소멸되기 때문에 얕은복사도 상관 없다
	m_pszData = rhs.m_pszData;
	m_nlength = rhs.m_nlength;

	//원본 임시 객체의 멤버들은 초기화한다. 절대로 해제하면 안된다.
	rhs.m_pszData = nullptr;
	rhs.m_nlength = 0;
}

//소멸자
CmyString::~CmyString() {
	Release();
}

int CmyString::SetString(const char* pszParam)
{
	Release();

	if (pszParam == nullptr)
		return 0;

	//문자열 길이
	int m_nlength = strlen(pszParam);
	
	//메모리 할당
	m_pszData = new char[m_nlength + 1];
	//문자열 복사
	strcpy_s(m_pszData, sizeof(char) * (m_nlength + 1), pszParam);

	return m_nlength;
}


const char* CmyString::GetString() const
{
	return m_pszData;
}


void CmyString::Release()
{
	//메모리 반환
	if(m_pszData!=nullptr)
		delete[] m_pszData;
	
	//주소 및 변수 초기화
	m_pszData = nullptr;
	m_nlength = 0;
}

CmyString& CmyString::operator=(const CmyString& rhs) {
	//정수형 복사
	m_nlength = rhs.m_nlength;

	//문자열 복사
	this->SetString(rhs.GetString());

	return *this;
}

CmyString::operator char* (void) const
{
	return m_pszData;
}