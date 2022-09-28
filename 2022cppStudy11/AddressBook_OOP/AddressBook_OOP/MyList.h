#pragma once

#include "UserData.h"
#include "string.h"
#include "conio.h"
#include <iostream>
#include "MyNode.h"
#include "MyIterator.h"

//노드 클래스에 대한 알림 선언
class CMyNode;

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	~CMyList(void);

protected:
	void ReleaseList(void);
	CMyNode* m_pHead;

public:
	CMyNode* FindNode(const char* pszKey);
	int AddNewNode(CMyNode *pNewNode);

	//void PrintAll(void);

	int RemoveNode(const char* pszKey);

	//열거자 생성
	CMyIterator MakeIterator(void);
	
	//데이터가 추가될 때마다 호출되는 가상 함수
	virtual int OnAddNewNode(CMyNode* pNewNode);
};