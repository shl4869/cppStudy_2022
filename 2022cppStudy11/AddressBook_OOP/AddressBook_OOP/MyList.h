#pragma once

#include "UserData.h"
#include "string.h"
#include "conio.h"
#include <iostream>
#include "MyNode.h"

//��� Ŭ������ ���� �˸� ����
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

	void PrintAll(void);

	int RemoveNode(const char* pszKey);

};