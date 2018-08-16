#include "listNode.h"
#include <vector>

int plen;
ListNode * FindKthToTail( ListNode * pListHead, unsigned int k )
{
	int len = 0;
	ListNode * temp = nullptr;
	std::vector<ListNode *> plist;
	if(pListHead->m_pNext == nullptr)
		return nullptr;
	for (temp = pListHead->m_pNext; temp != nullptr;temp = temp->m_pNext)
	{
		plist.push_back( temp );
		len++;
	}
	if ( len < k )
		return nullptr;
	else
		return plist[ len - k  ];
}

ListNode * FindKthToTail_2( ListNode * pListHead, unsigned int k )
{

	if ( plen < k )
		return nullptr;
	ListNode * ptmp=pListHead->m_pNext;
	int i = plen - k ;
	while ( i-- )
		ptmp = ptmp->m_pNext;
	return ptmp;
}

ListNode * add_value( std::vector<int> val )
{
	ListNode *head = new ListNode();
	head->m_pNext = nullptr;
	ListNode *ptemp = head;
	for ( auto tmp : val )
	{
		ptemp->m_pNext = new ListNode();
		ptemp = ptemp->m_pNext;
		ptemp->m_pNext = nullptr;


		ptemp->m_nKey = tmp;
	}
		return head;
}

void tmain()
{
	std::vector<int> val;

	std::cin >> plen;
	int tmp = plen;
	int value,k;
	ListNode * head = nullptr;
	while ( tmp-- )
	{
		std::cin >> value;
		val.push_back( value );
	}
	std::cin >> k;
	head = add_value( val );
	//ListNode* ptarget = FindKthToTail( head, k );//方式1
	ListNode* ptarget = FindKthToTail_2( head, k );//方式2
	std::cout << ptarget->m_nKey<<"\n";

}
