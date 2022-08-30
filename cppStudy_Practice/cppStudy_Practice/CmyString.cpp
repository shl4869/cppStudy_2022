#include "CmyString.h"
#include <cstring>

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