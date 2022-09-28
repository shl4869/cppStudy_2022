#pragma once
#include "MyNode.h"

class CMyIterator
{
	friend class CMyList;

public: 
	CMyIterator(void);
	~CMyIterator(void);

	CMyNode* GetuCurrent(void) const { return m_pCurrent; }
	void MoveNext(void)
	{
		if (m_pCurrent != nullptr)
			m_pCurrent = m_pCurrent->GetNext();
	}

private:
	CMyNode* m_pHead;
	CMyNode* m_pCurrent;
};

