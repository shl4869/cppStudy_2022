#pragma once
using namespace std;

class CmyString
{
public:
	CmyString();
	
	//���������
	CmyString(const CmyString& rhs);

	//��ȯ������
	explicit CmyString(const char*);
	
	//�̵�������
	CmyString(CmyString&& rhs);

	//�Ҹ���
	~CmyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
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

