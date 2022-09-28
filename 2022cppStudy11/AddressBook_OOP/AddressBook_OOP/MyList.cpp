#include "MyList.h"
#define DATA_FILE_NAME "Address.dat"

using namespace std;

CMyList::CMyList(CMyNode* pHead)
	:m_pHead(pHead)
{
	FILE* fp = NULL;
	CUserData* user = new CUserData();
	CMyNode* pNewNode;

	fopen_s(&fp, DATA_FILE_NAME, "rb");

	if (fp == NULL)
		return;

	ReleaseList();
//	m_pHead = pHead;

	while (fread(user, sizeof(CUserData), 1, fp))
	{
		pNewNode = new CUserData(user->GetName(), user->GetPhone());
		AddNewNode(pNewNode);
	}

	fclose(fp);
}

CMyList::~CMyList()
{
	FILE* fp = NULL;
	CUserData* pTmp = static_cast<CUserData*>(m_pHead->GetNext());

	fopen_s(&fp, DATA_FILE_NAME, "wb");

	if (fp == NULL) {
		puts("ERROR: ����Ʈ ������ ���� ���� ���� ���߽��ϴ�.");
		_getch();

		return;
	}

	while (pTmp != NULL) {
		if (fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
			printf("ERROR: %s�� ���� ������ �����ϴ� �� �����߽��ϴ�.\n", pTmp->GetKey());

		pTmp = static_cast<CUserData*>(pTmp->GetNext());
	}

	fclose(fp);

	ReleaseList();
}

int CMyList::AddNewNode(CMyNode* pNewNode)
{
	OnAddNewNode(pNewNode);

	if (FindNode(pNewNode->GetKey()) != NULL)
	{
		delete pNewNode;
		return 0;
	}
	
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;

	return 1;
}

//int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
//{
//	CUserData* pNewUser = NULL;
//
//	//���� �̸��� �̹� �����ϴ��� Ȯ���Ѵ�.
//	if (FindNode(pszName) != NULL)
//		return 0;
//
//	//�޸� Ȯ��
//	pNewUser = new CUserData();
//
//	//�޸𸮿� �� ����
//	strcpy_s(pNewUser->szName, sizeof(pNewUser->szName), pszName);
//	strcpy_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), pszPhone);
//	pNewUser->pNext = NULL;
//
//	//���� ��� �ٷ� �ڿ� ���δ�. ���� ���� �ֱٿ� �߰��� �����Ͱ� ���� ���ʿ� �´�.
//	pNewUser->pNext = m_Head.pNext;
//	m_Head.pNext = pNewUser;
//
//	return 1;
//}

//void CMyList::PrintAll(void)
//{
//	CMyNode* pTmp = m_pHead->pNext;
//	while (pTmp != NULL)
//	{
//		pTmp->PrintNode();
//		pTmp = pTmp->pNext;
//	}
//	cout << "CUserData Counter : " << CUserData::GetUserDataCounter() << endl;
//
//	_getch();
//}

CMyIterator CMyList::MakeIterator(void)
{
	CMyIterator myIterator;
	myIterator.m_pHead = m_pHead->pNext;
	myIterator.m_pCurrent = m_pHead->pNext;

	return myIterator;
}

int CMyList::OnAddNewNode(CMyNode* pNewNode)
{
	return 1;
}

CMyNode* CMyList::FindNode(const char* pszKey)
{
	CMyNode* pTmp(m_pHead->GetNext());
	while (pTmp != NULL) {
		if (strcmp(pTmp->GetKey(), pszKey) == 0)
			return pTmp;

		//���� ���� �̵�
		pTmp = pTmp->pNext;
	}

	//��ġ�ϴ� �����͸� ã�� ���� ���
	return NULL;
}

int CMyList::RemoveNode(const char* pszKey)
{
	CMyNode* pPrevNode = m_pHead;
	CMyNode* pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->GetKey(), pszKey) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}
		pPrevNode = pPrevNode->pNext;
	}
	return 0;
}

void CMyList::ReleaseList(void)
{
	CMyNode* pTmp = m_pHead->pNext;
	CMyNode* pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

//	memset(&m_pHead, 0, sizeof(CUserData));
	
}