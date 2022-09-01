#pragma once
using namespace std;

class CmyString
{
public:
	CmyString();
	
	//���������
	CmyString(const CmyString& rhs);

	//��ȯ������
	CmyString(const char*);
	
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
};

