#include "CmyString.h"
#include <cstring>
#include <iostream>

//������
CmyString::CmyString()
	:m_pszData(nullptr),m_nlength(0)
{

}

//���� ������
CmyString::CmyString(const CmyString& rhs) 
{
	//������ ����
	m_nlength = rhs.m_nlength;

	//���ڿ� ����
	m_pszData = new char[m_nlength + 1];
	this->SetString(rhs.GetString());
}

//��ȯ������
explicit CmyString::CmyString(const char* myStr)
	:m_pszData(nullptr), m_nlength(0)
{
	this->SetString(m_pszData);
}

//�̵�������
CmyString::CmyString(CmyString&& rhs)
	:m_pszData(nullptr), m_nlength(0)
{
	cout << "CmyString �̵������� ȣ��" << endl;

	//������ ������ �� �Ҹ�Ǳ� ������ �������絵 ��� ����
	m_pszData = rhs.m_pszData;
	m_nlength = rhs.m_nlength;

	//���� �ӽ� ��ü�� ������� �ʱ�ȭ�Ѵ�. ����� �����ϸ� �ȵȴ�.
	rhs.m_pszData = nullptr;
	rhs.m_nlength = 0;
}

//�Ҹ���
CmyString::~CmyString() {
	Release();
}

int CmyString::SetString(const char* pszParam)
{
	Release();

	if (pszParam == nullptr)
		return 0;

	//���ڿ� ����
	int m_nlength = strlen(pszParam);
	
	//�޸� �Ҵ�
	m_pszData = new char[m_nlength + 1];
	//���ڿ� ����
	strcpy_s(m_pszData, sizeof(char) * (m_nlength + 1), pszParam);

	return m_nlength;
}


const char* CmyString::GetString() const
{
	return m_pszData;
}


void CmyString::Release()
{
	//�޸� ��ȯ
	if(m_pszData!=nullptr)
		delete[] m_pszData;
	
	//�ּ� �� ���� �ʱ�ȭ
	m_pszData = nullptr;
	m_nlength = 0;
}

CmyString& CmyString::operator=(const CmyString& rhs) {
	//������ ����
	m_nlength = rhs.m_nlength;

	//���ڿ� ����
	this->SetString(rhs.GetString());

	return *this;
}

CmyString::operator char* (void) const
{
	return m_pszData;
}