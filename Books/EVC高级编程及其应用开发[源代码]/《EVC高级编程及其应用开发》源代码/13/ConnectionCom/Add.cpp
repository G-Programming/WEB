// Add.cpp : Implementation of CAdd
#include "stdafx.h"
#include "ConnectionCom.h"
#include "Add.h"

/////////////////////////////////////////////////////////////////////////////
// CAdd


STDMETHODIMP CAdd::Add(int a, int b)
{
	//��һ����ʱ
    Sleep(2000);   
	//�������ӵ��¼�
    Fire_ExecutionOver(a+b);

	return S_OK;
}
