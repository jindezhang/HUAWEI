#ifndef LIST_H_
#define LIST_H_

#include <vector>
#include <iostream>

struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;

};

ListNode* FindKthToTail( ListNode *pListHead, unsigned int k );
ListNode* FindKthToTail_2( ListNode *pListHead, unsigned int k );
ListNode *add_value( std::vector<int> val );
void tmain();

#endif

#pragma once
