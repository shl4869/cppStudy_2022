#include "CmyString.h"
#include <cstring>
CmyString::CmyString()
	:m_pszData(nullptr),m_nlength(0)
{

}

CmyString::~CmyString() {
	Release();
}

int CmyString::SetString(const char* pszParam)
{
	// TODO: 여기에 구현 코드 추가.
	Release();

	if (pszParam == nullptr)
		return 0;

	int m_nlength = strlen(pszParam);
	m_pszData = new char[m_nlength + 1];
	strcpy_s(m_pszData, sizeof(char) * (m_nlength + 1), pszParam);

	return m_nlength;
}


const char* CmyString::GetString() const
{
	// TODO: 여기에 구현 코드 추가.
	return m_pszData;
}


void CmyString::Release()
{
	if(m_pszData!=nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nlength = 0;
}
