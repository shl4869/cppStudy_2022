#pragma once

#include "MyList.h"
#include "string.h"
#include "conio.h"
#include <iostream>

using namespace std;

class CMyList;

class CUserInterface
{
public:
	CUserInterface(CMyList& rList);
	~CUserInterface(void);

protected:
	CMyList& m_List;

public:
	void Add(void);

	void Search(void);

	void Remove(void);

	int PrintUI(void);

	int Run(void);
};

