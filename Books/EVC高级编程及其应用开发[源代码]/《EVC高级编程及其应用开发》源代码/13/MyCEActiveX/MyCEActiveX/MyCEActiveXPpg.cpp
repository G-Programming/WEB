// MyCEActiveXPpg.cpp : Implementation of the CMyCEActiveXPropPage property page class.

#include "stdafx.h"
#include "MyCEActiveX.h"
#include "MyCEActiveXPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMyCEActiveXPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMyCEActiveXPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CMyCEActiveXPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMyCEActiveXPropPage, "MYCEACTIVEX.MyCEActiveXPropPage.1",
	0x60499b42, 0x9b71, 0x453a, 0x91, 0x84, 0xfc, 0x97, 0xee, 0x78, 0x14, 0xf9)


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXPropPage::CMyCEActiveXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMyCEActiveXPropPage

BOOL CMyCEActiveXPropPage::CMyCEActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYCEACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXPropPage::CMyCEActiveXPropPage - Constructor

CMyCEActiveXPropPage::CMyCEActiveXPropPage() :
	COlePropertyPage(IDD, IDS_MYCEACTIVEX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CMyCEActiveXPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXPropPage::DoDataExchange - Moves data between page and properties

void CMyCEActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CMyCEActiveXPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXPropPage message handlers
