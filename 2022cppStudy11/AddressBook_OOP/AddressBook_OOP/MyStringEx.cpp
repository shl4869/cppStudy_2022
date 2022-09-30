#include "MyStringEx.h"

CMyStringEx::CMyStringEx()	//�⺻������
{

}

CMyStringEx::CMyStringEx(const char* pszParam)	//��ȯ������
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

	if (Find("�۸��̾Ƶ�") != -1)
		nResult = CmyString::SetString("���ѻ��");

	return nResult;
}