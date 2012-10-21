#include "testmetagen.h"
#include "../include/testobjectarray.h"
#include "../metadata/include/meta_test_testobjectarray.h"


using namespace meta_test;
using namespace std;

namespace {


void testObjectArray(TestScriptContext * context)
{
	if(context->isPython()) {
		QDO(null = None);
	}
	QDO(cpgf.loadLibrary(null, "builtin.arrays.objectarray"));
	QDO(oa = cpgf.createObjectArray(mtest.OAObject));
	
	QNEWOBJ(obj, mtest.OAObject(98, "def"));
	QDO(oa.setItem(0, obj));
	QNEWOBJ(obj, mtest.OAObject(38, "abc"));
	QDO(oa.setItem(1, obj));
	QNEWOBJ(obj, mtest.OAObject(0, ""));
	QDO(oa.setItem(2, obj));

	QASSERT(oa.getItem(0).data.n == 98);
	QASSERT(oa.getItem(0).data.s == "def");
	QASSERT(mtest.getOAObjectN(oa.getItem(0)) == 98);
	QASSERT(mtest.getOAObjectS(oa.getItem(0)) == "def");
	QASSERT(mtest.getOAObjectN(oa.getItem(0), 0) == 98); // equivalent to (&oa[0])[0]

	QASSERT(oa.getItem(1).data.n == 38);
	QASSERT(oa.getItem(1).data.s == "abc");
	QASSERT(mtest.getOAObjectN(oa.getItem(1)) == 38);
	QASSERT(mtest.getOAObjectS(oa.getItem(1)) == "abc");
	QASSERT(mtest.getOAObjectN(oa.getItem(0), 1) == 38); // equivalent to (&oa[0])[1]

	QDO(oa.getItem(2).data.n = 1999);
	QDO(oa.getItem(2).data.s = "what");
	QASSERT(oa.getItem(2).data.n == 1999);
	QASSERT(oa.getItem(2).data.s == "what");
	QASSERT(mtest.getOAObjectN(oa.getItem(2)) == 1999);
	QASSERT(mtest.getOAObjectS(oa.getItem(2)) == "what");
	QASSERT(mtest.getOAObjectN(oa.getItem(0), 2) == 1999); // equivalent to (&oa[0])[2]
	QASSERT(mtest.getOAObjectN(oa.getItem(1), 1) == 1999); // equivalent to (&oa[1])[1]
}

#define CASE testObjectArray
#include "do_testcase.h"



}
