#pragma once

class CMyNode
{
	friend class CMyList;
public:
	CMyNode(void);
	virtual ~CMyNode(void);

	CMyNode* GetNext(void) const { return pNext; }

	//������ ���� �� �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const char* GetKey(void) = 0;
	virtual void PrintNode(void) = 0;

private:
	//���Ḯ��Ʈ ��ü�� ���� ���
	CMyNode* pNext;
};

