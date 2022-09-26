#include "UserData.h"
#include "string.h"
#include <iostream>

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
	//:pNext(nullptr)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	strcpy_s(szName, sizeof(szName), pszName);
	strcpy_s(szPhone, sizeof(szPhone), pszPhone);

	nUserDataCounter++;
}

CUserData::~CUserData(void)
{
	nUserDataCounter--;
}

const char* CUserData::GetKey(void)
{
	return szName;
}

void CUserData::PrintNode(void)
{
	std::cout << "[" << this << "] "
		<< szName << "\t"
		<< szPhone
		<< "[" << GetNext() << "]" << std::endl;
	//pNext�� private ����̹Ƿ� GetNext()�� ���� �ʰ��� �Ļ�Ŭ�������� ���� �Ұ�
}