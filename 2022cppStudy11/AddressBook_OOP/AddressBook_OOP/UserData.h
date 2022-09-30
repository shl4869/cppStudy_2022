#pragma once
#include "MyNode.h"
#include "CmyString.h"

//CMyNode Ŭ������ �Ļ� Ŭ������ ����
class CUserData :public CMyNode
{
	friend class CMyList;

public:
	CUserData(void);
	CUserData(const char* pszName, const char* pszPhone);
	~CUserData(void);

	const char* GetName(void) const { /*return szName;*/ return strName.GetString(); }
	const char* GetPhone(void) const { /*return szPhone;*/ return strPhone.GetString(); }
	//const CUserData* GetNext(void) const { return pNext; }
	
	static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
	//char szName[32];	//�̸�
	//char szPhone[32];	//��ȭ��ȣ

	//CUserData* pNext;

	CmyString strName;
	CmyString strPhone;

	static int nUserDataCounter;

public:
	//���� ���� �Լ��� ����
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
};

