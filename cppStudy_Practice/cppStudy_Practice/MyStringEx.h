#pragma once
#include "CmyString.h"
#include <cstring>
using namespace std;

class CMyStringEx :
    public CmyString
{
public:
    CMyStringEx();
    explicit CMyStringEx(const char*);
    ~CMyStringEx();

    int Find(const char* pszParam);
    int SetString(const char* pszParam);
};

