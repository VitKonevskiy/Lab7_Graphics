#pragma once
#include "TObject.h"
#include "TList_and_TLink.h"
using namespace System::Drawing;

class TGroup :public TObject
{
protected:
	TList<TObject*> List;
public:
	virtual void Draw(Graphics ^gr)
	{
		for (List.Reset(); !List.IsEnd(); List.GoNext())
		{
			List.GetCurrentVal()->Draw(gr);
		}
	}
	virtual void Hide(Graphics ^gr)
	{
		for (List.Reset(); !List.IsEnd(); List.GoNext())
		{
			List.GetCurrentVal()->Hide(gr);
		}
	}
	virtual void Move(Graphics ^gr,int dx,int dy)
	{
		for (List.Reset(); !List.IsEnd(); List.GoNext())
		{
			List.GetCurrentVal()->Move(gr,dx,dy);
		}
	}
	void Insert(TObject *p)
	{
		List.AddFirst(p);
	}
};