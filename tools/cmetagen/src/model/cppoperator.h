#ifndef __CPPOPERATOR_H
#define __CPPOPERATOR_H

#include "cppitem.h"
#include "cppinvokable.h"
#include "cpptemplateitem.h"


class CppOperator : public CppInvokable, public CppTemplateItem
{
protected:
	virtual ItemCategory getCategory() const { return icOperator; }
};


#endif