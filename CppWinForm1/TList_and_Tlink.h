#pragma once
#include <stdlib.h>

template <class T>
class TLink
{
public:
	T Val;                                 // «начение
	TLink* pNext;                          // ”казатель на след элемент

	explicit TLink(const T& _Val = T());
	TLink(const TLink& L);
	~TLink();

	T& GetVal() { return Val; }
};

template <class T>
TLink<T>::TLink(const T& _Val)
{
	Val = _Val;
	pNext = NULL;                           // шаблон по умолчанию - "пустой" полином
}

template <class T>
TLink<T>::TLink(const TLink& L)
{
	Val = L.Val;
	pNext = L.pNext;
}

template <class T>
TLink<T>::~TLink()
{
}

template <class T>
class TList
{
	TLink<T> *pFirst;
	TLink<T> *pCurrent;
public:
	TList()
	{
		pCurrent = pFirst = NULL;
	}
	void AddFirst(T elem)
	{
		TLink <T>* tmp;
		tmp = new TLink<T>;
		tmp->Val = elem;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	void AddLast(T elem)
	{
		TLink <T>* tmp;
		tmp = new TLink<T>;
		tmp->Val = elem;
		tmp->pNext = NULL;
		TLink <T>* Curr=pFirst;
		while (Curr->pNext != NULL)
			Curr = Curr->pNext;
		Curr->pNext = tmp;
	}
	bool IsEnd()
	{
		if (pCurrent == NULL)
			return true;
		else return false;
	}
	void Reset()
	{
		if (pFirst != NULL)
			pCurrent = pFirst;
	}
	void GoNext()
	{
		if(pCurrent!=NULL)
			pCurrent = pCurrent->pNext;
	}
	T GetCurrentVal()
	{
		if (pCurrent != NULL)
			return pCurrent->Val;
		else return -1;
	}
};


