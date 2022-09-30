#pragma once
using namespace std;

class CmyString
{
public:
	CmyString();
	
	//복사생성자
	CmyString(const CmyString& rhs);

	//변환생성자
	explicit CmyString(const char*);
	
	//이동생성자
	CmyString(CmyString&& rhs);

	//소멸자
	~CmyString();

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;

	// 저장된 문자열의 길이
	int m_nlength;

public:

	int SetString(const char* pszParam);
	const char* GetString() const;
	
	void Release();
	
	CmyString& operator = (const CmyString& rhs);
	operator char* (void) const;
	CmyString operator + (const CmyString& rhs);
	CmyString& operator += (const CmyString& rhs);
	char operator[](int nIndex) const;
	char& operator [](int nIndex);
	int operator == (const CmyString& rhs);
	int operator != (const CmyString& rhs);

	friend CmyString operator + (const char* pszParam, const CmyString& strParam);

	int GetLength() const;
	int Append(const char* pszParam);

	virtual void OnSetString(char* pszData, int nLength);
};

