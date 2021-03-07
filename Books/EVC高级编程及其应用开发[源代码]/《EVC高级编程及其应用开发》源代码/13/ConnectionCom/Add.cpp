// Add.cpp : Implementation of CAdd
#include "stdafx.h"
#include "ConnectionCom.h"
#include "Add.h"

/////////////////////////////////////////////////////////////////////////////
// CAdd


STDMETHODIMP CAdd::Add(int a, int b)
{
	//做一下延时
    Sleep(2000);   
	//触发连接点事件
    Fire_ExecutionOver(a+b);

	return S_OK;
}
