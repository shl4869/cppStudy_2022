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
/*explicit */CmyString::CmyString(const char* myStr)
	:m_pszData(nullptr), m_nlength(0)
{
	//cout << "변환생성자call" << endl;
	this->SetString(myStr);
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
	m_nlength = (int)strlen(pszParam);

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

int CmyString::GetLength() const
{
	return m_nlength;
}

int CmyString::Append(const char* pszParam) {
	
	//매개변수 유효성 검사
	if (pszParam == NULL)
		return 0;
	
	int nLenParam = (int)strlen(pszParam);
	
	//세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리함
	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nlength;
	}

	//현재 문자열의 길이 백업
	int nLenCur = m_nlength;

	//두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당함
	char* pszResult = new char[nLenCur + nLenParam + 1];

	//문자열 조합
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	//기존 문자열 삭제 및 멤버 정보 갱신
	Release();
	m_pszData = pszResult;
	m_nlength = nLenCur + nLenParam;

	//cout << "AppendReturn" << endl;
	return m_nlength;

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

CmyString CmyString::operator + (const CmyString& rhs) 
{
	CmyString resultSTR(m_pszData);
	resultSTR.Append(rhs.GetString());
	return resultSTR;
}

CmyString& CmyString::operator += (const CmyString& rhs)
{
	Append(rhs.GetString());
	return *this;
}

char CmyString::operator [](int nIndex) const
{
	return m_pszData[nIndex];
}

char& CmyString::operator [](int nIndex)
{
	return m_pszData[nIndex];
}

int CmyString::operator ==(const CmyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;
	return 0;
}

int CmyString::operator !=(const CmyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;
	return 1;
}