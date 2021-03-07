// MyCEActiveXCtl.cpp : Implementation of the CMyCEActiveXCtrl ActiveX Control class.

#include "stdafx.h"
#include "MyCEActiveX.h"
#include "MyCEActiveXCtl.h"
#include "MyCEActiveXPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMyCEActiveXCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMyCEActiveXCtrl, COleControl)
	//{{AFX_MSG_MAP(CMyCEActiveXCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CMyCEActiveXCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CMyCEActiveXCtrl)
	DISP_PROPERTY_EX(CMyCEActiveXCtrl, "MsgContext", GetMsgContext, SetMsgContext, VT_BSTR)
	DISP_FUNCTION(CMyCEActiveXCtrl, "ShowMessage", ShowMessage, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CMyCEActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CMyCEActiveXCtrl, COleControl)
	//{{AFX_EVENT_MAP(CMyCEActiveXCtrl)
	EVENT_CUSTOM("OnMsgChange", FireOnMsgChange, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMyCEActiveXCtrl, 1)
	PROPPAGEID(CMyCEActiveXPropPage::guid)
END_PROPPAGEIDS(CMyCEActiveXCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMyCEActiveXCtrl, "MYCEACTIVEX.MyCEActiveXCtrl.1",
	0x6842371a, 0x9b5a, 0x4b9b, 0xb3, 0xb4, 0x75, 0x8, 0x39, 0x89, 0x8b, 0xcb)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CMyCEActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DMyCEActiveX =
		{ 0x9b93ff7, 0x2e64, 0x4143, { 0x9c, 0x69, 0x18, 0xee, 0xcc, 0x23, 0xe5, 0xdf } };
const IID BASED_CODE IID_DMyCEActiveXEvents =
		{ 0x6cbfeabe, 0x53be, 0x41ad, { 0x9c, 0xa7, 0xd5, 0xe5, 0x2b, 0xc8, 0xb6, 0xc4 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwMyCEActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMyCEActiveXCtrl, IDS_MYCEACTIVEX, _dwMyCEActiveXOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::CMyCEActiveXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMyCEActiveXCtrl

BOOL CMyCEActiveXCtrl::CMyCEActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MYCEACTIVEX,
			IDB_MYCEACTIVEX,
			afxRegApartmentThreading,
			_dwMyCEActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::CMyCEActiveXCtrl - Constructor

CMyCEActiveXCtrl::CMyCEActiveXCtrl()
{
	InitializeIIDs(&IID_DMyCEActiveX, &IID_DMyCEActiveXEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::~CMyCEActiveXCtrl - Destructor

CMyCEActiveXCtrl::~CMyCEActiveXCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::OnDraw - Drawing function

void CMyCEActiveXCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::DoPropExchange - Persistence support

void CMyCEActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_String(pPX,L"MsgContext",m_MsgContext,L"ª∂”≠ π”√¥ÀAcitvex£¨∫«∫«");
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::OnResetState - Reset control to default state

void CMyCEActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl::AboutBox - Display an "About" box to the user

void CMyCEActiveXCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_MYCEACTIVEX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl message handlers

BSTR CMyCEActiveXCtrl::GetMsgContext() 
{
	return m_MsgContext.AllocSysString();
}

void CMyCEActiveXCtrl::SetMsgContext(LPCTSTR lpszNewValue) 
{
	if (m_MsgContext.Compare(lpszNewValue) != 0 )
	{
		m_MsgContext = lpszNewValue;
		FireOnMsgChange();
		SetModifiedFlag();
	}
}

void CMyCEActiveXCtrl::ShowMessage() 
{
	AfxMessageBox(m_MsgContext);
}
