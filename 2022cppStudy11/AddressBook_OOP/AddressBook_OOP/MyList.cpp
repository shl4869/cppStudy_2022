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
		puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
		_getch();

		return;
	}

	while (pTmp != NULL) {
		if (fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
			printf("ERROR: %s에 대한 정보를 저장하는 데 실패했습니다.\n", pTmp->GetKey());

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
//	//같은 이름이 이미 존재하는지 확인한다.
//	if (FindNode(pszName) != NULL)
//		return 0;
//
//	//메모리 확보
//	pNewUser = new CUserData();
//
//	//메모리에 값 저장
//	strcpy_s(pNewUser->szName, sizeof(pNewUser->szName), pszName);
//	strcpy_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), pszPhone);
//	pNewUser->pNext = NULL;
//
//	//더미 노드 바로 뒤에 붙인다. 따라서 가장 최근에 추가한 데이터가 가장 앞쪽에 온다.
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

		//다음 노드로 이동
		pTmp = pTmp->pNext;
	}

	//일치하는 데이터를 찾지 못한 경우
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