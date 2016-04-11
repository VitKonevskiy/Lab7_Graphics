#pragma once
#include "TObject.h"
#include <stdlib.h>

class TChart :public TObject
{
protected:
	TObject *begin, *end;
public:
	TChart()
	{
		begin = end = NULL;
	}
	TObject *GetFirst()
	{
		return begin;
	}
	void SetFirst(TObject *p)
	{
		begin = p;
	}
};
