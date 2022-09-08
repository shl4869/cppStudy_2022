#include "MyStringEx.h"

CMyStringEx::CMyStringEx()	//기본생성자
{

}

CMyStringEx::CMyStringEx(const char* pszParam)	//변환생성자
	:CmyString::CmyString(pszParam)
{

}

CMyStringEx::~CMyStringEx()
{

}



int CMyStringEx::Find(const char* pszParam)
{
	const char* indexptr = strstr(this->GetString(), pszParam);

	if (indexptr == NULL||this->GetString()==NULL)
		return -1;

	int nIndex(-1);
	nIndex = (int)((indexptr - this->GetString()) / sizeof(char));

	return nIndex;
}

int CMyStringEx::SetString(const char* pszParam)
{
	int nResult;
	nResult = CmyString::SetString(pszParam);

	if (Find("멍멍이아들") != -1)
		nResult = CmyString::SetString("착한사람");

	return nResult;
}