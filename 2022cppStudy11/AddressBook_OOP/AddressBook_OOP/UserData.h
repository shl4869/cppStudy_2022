#pragma once
#include "MyNode.h"
#include "CmyString.h"

//CMyNode 클래스의 파생 클래스로 변경
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
	//char szName[32];	//이름
	//char szPhone[32];	//전화번호

	//CUserData* pNext;

	CmyString strName;
	CmyString strPhone;

	static int nUserDataCounter;

public:
	//순수 가상 함수들 정의
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
};

