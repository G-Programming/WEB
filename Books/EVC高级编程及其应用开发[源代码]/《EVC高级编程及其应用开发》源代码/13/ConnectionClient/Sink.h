// Sink.h: interface for the CSink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINK_H__9E09EFB0_6748_4FF1_A4BA_048AAA66194B__INCLUDED_)
#define AFX_SINK_H__9E09EFB0_6748_4FF1_A4BA_048AAA66194B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConnectionCOM.h"
#import "ConnectionCOM.tlb" named_guids raw_interfaces_only


class CSink : public _IAddEvents  
{
private:
	DWORD       m_dwRefCount;
	
public:
	CSink();
	virtual ~CSink();
public:
	public:
	//1、实现_IAddComEvents接口的ExecutionOver方法
	STDMETHODIMP ExecutionOver(int Result)
	{
		CString strTemp;
		strTemp.Format(L"结果是: %d", Result);
		AfxMessageBox(strTemp);
		return S_OK;;
		
	};
	
	//2、实现_IAddComEvents接口的QueryInterface方法
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void
		**ppvObject)
	{
		if (iid == IID__IAddEvents)
		{
			m_dwRefCount++;
			*ppvObject = (void *)this;
			return S_OK;
		}
		if (iid == IID_IUnknown)
		{
			m_dwRefCount++;
			*ppvObject = (void *)this;
			return S_OK;
		}
		return E_NOINTERFACE;
	}
	
	//3、实现_IAddComEvents接口的AddRef方法
	ULONG STDMETHODCALLTYPE AddRef()
	{
		m_dwRefCount++;
		return m_dwRefCount;
	}
	
	//4、实现_IAddComEvents接口的Release方法
	ULONG STDMETHODCALLTYPE Release()
	{
		ULONG l;
		l  = m_dwRefCount--;
		if ( 0 == m_dwRefCount)
			delete this;
		
		return l;
	}

};
#endif // !defined(AFX_SINK_H__9E09EFB0_6748_4FF1_A4BA_048AAA66194B__INCLUDED_)
