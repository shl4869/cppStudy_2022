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
/*explicit */CmyString::CmyString(const char* myStr)
	:m_pszData(nullptr), m_nlength(0)
{
	//cout << "��ȯ������call" << endl;
	this->SetString(myStr);
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
	m_nlength = (int)strlen(pszParam);

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

int CmyString::GetLength() const
{
	return m_nlength;
}

int CmyString::Append(const char* pszParam) {
	
	//�Ű����� ��ȿ�� �˻�
	if (pszParam == NULL)
		return 0;
	
	int nLenParam = (int)strlen(pszParam);
	
	//��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó����
	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nlength;
	}

	//���� ���ڿ��� ���� ���
	int nLenCur = m_nlength;

	//�� ���ڿ��� ���ļ� ������ �� �ִ� �޸𸮸� ���� �Ҵ���
	char* pszResult = new char[nLenCur + nLenParam + 1];

	//���ڿ� ����
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	//���� ���ڿ� ���� �� ��� ���� ����
	Release();
	m_pszData = pszResult;
	m_nlength = nLenCur + nLenParam;

	//cout << "AppendReturn" << endl;
	return m_nlength;

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

CmyString CmyString::operator + (const CmyString& rhs) 
{
	CmyString resultSTR(m_pszData);
	resultSTR.Append(rhs.GetString());
	return resultSTR;
}

CmyString& CmyString::operator += (const CmyString& rhs)
{
	Append(rhs.GetString());
	return *this;
}

char CmyString::operator [](int nIndex) const
{
	return m_pszData[nIndex];
}

char& CmyString::operator [](int nIndex)
{
	return m_pszData[nIndex];
}

int CmyString::operator ==(const CmyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;
	return 0;
}

int CmyString::operator !=(const CmyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;
	return 1;
}