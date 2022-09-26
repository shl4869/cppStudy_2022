#include "UserInterFace.h"

CUserInterface::CUserInterface(CMyList& rList)
	:m_List(rList)
{

}

CUserInterface::~CUserInterface()
{

}

void CUserInterface::Add(void)
{
	char* szName = new char[32];
	char* szPhone = new char[32];

	cout << "Input name : ";
	cin >> szName;

	cout << "Input phone number : ";
	cin >> szPhone;

	m_List.AddNewNode(new CUserData(szName, szPhone));

}

void CUserInterface::Search(void)
{
	char* szName = new char[32];
	CMyNode* pNode = NULL;

	cout << "Input name : ";
	cin >> szName;

	pNode = m_List.FindNode(szName);
	if (pNode != NULL)
	{
		pNode->PrintNode();
		/*cout << "[" << pNode << "] "
			<< pNode->GetName() << "\t"
			<< pNode->GetPhone()
			<< "[" << pNode->GetNext() << "]" << endl;*/
	}
	_getch();

}

void CUserInterface::Remove(void)
{
	char* szName = new char[32];
	cout << "Input name : ";
	cin >> szName;
	cout << "inputend" << endl;

	m_List.RemoveNode(szName);
	cout << "removeEnd" << endl;
	return;
}

int CUserInterface::PrintUI(void)
{
	int nInput = 0;

	system("cls");
	printf("\n[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	cin >> nInput;

	return nInput;
}

int CUserInterface::Run()
{
	int nMenu = 0;

	//���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:	//Add
			Add();
			break;

		case 2:	//Search
			Search();
			break;

		case 3:	//Print all
			m_List.PrintAll();
			break;

		case 4:
			Remove();
			break;
		}
	}

	return nMenu;
}