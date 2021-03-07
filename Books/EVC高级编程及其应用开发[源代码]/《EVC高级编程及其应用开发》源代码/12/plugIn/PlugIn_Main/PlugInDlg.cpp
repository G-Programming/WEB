// PlugInDlg.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "PlugInDlg.h"
#include "MainFrm.h"
#include "DLLManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlugInDlg dialog


CPlugInDlg::CPlugInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlugInDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlugInDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPlugInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlugInDlg)
	DDX_Control(pDX, IDC_LSTPLUGIN, m_lstPlugIn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlugInDlg, CDialog)
	//{{AFX_MSG_MAP(CPlugInDlg)
	ON_BN_CLICKED(IDC_BTNLOAD, OnBtnload)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlugInDlg message handlers


/*
*�������ܣ��������Ϣ��䵽�б���ͼ
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��(��)
*/
void CPlugInDlg::FillPlugIns(void)
{
	CRect           rect;
	CString         strItem1= _T("���");
	CString         strItem2= _T("�������");
	CString         strItem3= _T("����ļ���");
	CString         szSerialNo(""), szPlugInName(""), szPlugInPath("");
	LPTSTR          pStrTemp1 = NULL, pStrTemp2 = NULL, pStrTemp3 = NULL;
	CPlugIn_MainApp     *pApp = NULL;
	
	pApp = (CPlugIn_MainApp *)AfxGetApp();
	
	int nNumDLLsFound = FindDLLs(pApp);
	
	//�����б���ͼ���б���
	m_lstPlugIn.GetWindowRect(&rect);
	m_lstPlugIn.InsertColumn(0, strItem1, LVCFMT_LEFT, rect.Width() * 4/20);
	m_lstPlugIn.InsertColumn(1, strItem2, LVCFMT_LEFT, rect.Width() * 6/20);
	m_lstPlugIn.InsertColumn(2, strItem3, LVCFMT_LEFT, rect.Width() * 10/20);
	
	POSITION pos1 = m_szListPlugInName.GetHeadPosition();
	POSITION pos2 = m_szListValidFilenames.GetHeadPosition();
	
	//���б���ͼ����Ӳ����Ϣ
	for (int nItem = 0; nItem < nNumDLLsFound; nItem++)
	{
		szPlugInName = m_szListPlugInName.GetNext(pos1);
		szPlugInPath = m_szListValidFilenames.GetNext(pos2);
		szSerialNo.Format(_T("%d"), nItem);

			
		pStrTemp1= szSerialNo.GetBuffer(szSerialNo.GetLength());
		pStrTemp2= szPlugInName.GetBuffer(szPlugInName.GetLength());
		pStrTemp3= szPlugInPath.GetBuffer(szPlugInPath.GetLength());

        m_lstPlugIn.InsertItem(nItem,pStrTemp1);
        m_lstPlugIn.SetItemText(nItem,0,pStrTemp1);
	    m_lstPlugIn.SetItemText(nItem,1,pStrTemp2);
	    m_lstPlugIn.SetItemText(nItem,2,pStrTemp3);	 
	
		//�жϲ���Ƿ��ѱ�����
		if (((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.Find(szPlugInPath) != NULL)
		{
			ListView_SetCheckState(m_lstPlugIn.m_hWnd, nItem, TRUE);
		}
	}
	m_szListPlugInName.RemoveAll();
	m_szListValidFilenames.RemoveAll();
}


/*
*�������ܣ�����ͬ��ִ���ļ���ͬĿ¼�µ�.plx����ļ���������洢���б���
*��ڲ�����pApp:ָ��CPlugIn_MainAppӦ�ó������ָ��
*���ڲ�����(��)
*�� �� ֵ�������ҵ����������
*/
int CPlugInDlg::FindDLLs(CPlugIn_MainApp *pApp)
{
	//��������ļ����
	HANDLE hFile;
	//��������ļ��ṹ
	WIN32_FIND_DATA FileData;
	CDLLManager			tmpDLL;
	//���ò��Ҳ��·��
	CString				szSearchPath = _T("");
	CString				szCommandLine ;
	int					nNumDlls = 0 ;
    TCHAR exeFullPath[MAX_PATH] ;
    GetModuleFileName(NULL,exeFullPath,MAX_PATH);
    szCommandLine = exeFullPath;
	//ȥ��Exe�ļ���
	szCommandLine = szCommandLine.Left(szCommandLine.Find(_T("PlugIn_Main.exe")));
	szCommandLine = szCommandLine.Right(szCommandLine.GetLength() - 1);
	//���ò����ļ�·��
	szSearchPath = szCommandLine + "*.PLX";
	//���ҵ�һ�������������ļ�
	hFile = FindFirstFile (szSearchPath, &FileData);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			//���ù���������ָ��
			tmpDLL.SetToolBarPointer(((CMainFrame *)pApp->m_pMainWnd)->GetToolBarObject());
			//���ò��DLL�ļ���
			tmpDLL.SetDLLFileName(szCommandLine + FileData.cFileName);
			CString szName(_T(""));
			if (tmpDLL.GetDLLName(&szName) == true)
			{
				//��������ƺ��ļ����洢���б���
				m_szListPlugInName.AddTail(szName);
				m_szListValidFilenames.AddTail(tmpDLL.m_szDLLFileName);
				nNumDlls++;
			}
		} while (FindNextFile(hFile, &FileData) != 0);
		//�رղ����ļ����
		FindClose(hFile);
	}
	return nNumDlls;
}

/*
*�������ܣ�����ѡ�еĲ���б�
*��ڲ�����pApp:ָ��CPlugIn_MainAppӦ�ó������ָ��
		   szListSelectedDLLs : ѡ�еĲ���б�
*���ڲ�����(��)
*�� �� ֵ��TRUE:���سɹ� ; FALSE: ����ʧ��
*/
bool CPlugInDlg::LoadDLLs(CPlugIn_MainApp *pApp, CStringList *szListSelectedDLLs)
{
	//�жϼ���dll������
	if (((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs > 0)
	{
		POSITION pos = szListSelectedDLLs->GetHeadPosition();
		((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs = new CDLLManager[((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs];
		for (int nNumDlls = 0 ;	nNumDlls < ((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs ; nNumDlls++)
		{
			((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].SetToolBarPointer(((CMainFrame *)pApp->m_pMainWnd)->GetToolBarObject());
            if (((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].LoadDLL(szListSelectedDLLs->GetNext(pos)) != false)
			{
				if (((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].InitDLL() == false)
				{
					AfxMessageBox(_T("����: ��ʼ�� " + ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].m_szDLLFileName + "ʧ��!!!"));
					return false;
				}
			}
			else
			{
				AfxMessageBox(_T("����: ���� " + ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].m_szDLLFileName + "ʧ��!!!"));
				
				return false;
			}
		}
	}
	else
	{
		AfxMessageBox(_T("����û�б����ص�DLL"));
		return false;
	}
	
	//���²��ý�����ʾ
	((CMainFrame *)pApp->m_pMainWnd)->RecalcLayout();
	
	//���ñ�ʶ����ʶ����ѱ�����
	((CMainFrame *)pApp->m_pMainWnd)->m_bIsPlugInLoaded = TRUE;
	
	return true;
}


BOOL CPlugInDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//�����б���ͼ��ʽ
	m_lstPlugIn.SetExtendedStyle(m_lstPlugIn.GetExtendedStyle()
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_GRIDLINES
		| 0x00004000 // LVS_EX_LABELTIP
		| LVS_EX_FULLROWSELECT
		| LVS_EX_CHECKBOXES);
	//�����
	FillPlugIns();
	
	m_lstPlugIn.SetFocus();
	if (m_lstPlugIn.GetItemCount() > 0)
        m_lstPlugIn.SetSelectionMark(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//���ذ�ť��������
void CPlugInDlg::OnBtnload() 
{
	int nCount = m_lstPlugIn.GetItemCount();
	int nNumDLLsSelected = 0;
	
	if (nCount <= 0)
	{
		AfxMessageBox(_T("û�в��������"));
		return;
	}
	
	CStringList szList;
	
	for (int i=0; i<m_lstPlugIn.GetItemCount(); i++)
	{
		if (ListView_GetCheckState(m_lstPlugIn.m_hWnd, i) != 0)
		{
			szList.AddTail(m_lstPlugIn.GetItemText(i, 2));
			++nNumDLLsSelected;
		}
	}
	
	if (nNumDLLsSelected == 0)
	{
		if (AfxMessageBox(_T("����: û��ѡ�в����������ж�ز����"),MB_YESNO) == IDYES)
		{
			CPlugIn_MainApp *pApp = (CPlugIn_MainApp *) AfxGetApp();
			
			if (((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs > 0)
			{
				//ɾ�����������صĲ��
				delete [] ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs;
				((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs = NULL;
				((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = 0;
				((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.RemoveAll();
				
				//���²��ý�����ʾ
				((CMainFrame *)pApp->m_pMainWnd)->RecalcLayout();
			}
			
			((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = 0;
		}
		return;
	}
	else
	{
		CPlugIn_MainApp *pApp = (CPlugIn_MainApp *) AfxGetApp();
		
		if (((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs > 0)
		{
			//ɾ�����������صĲ��
			delete [] ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs;
			((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs = NULL;
			((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = 0;
			
			// Recalculate layout due to GUI changes
			((CMainFrame *)pApp->m_pMainWnd)->RecalcLayout();
		}
		
		//���²��ý�����ʾ
		((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = nNumDLLsSelected;
		
		//���¼��ز��DLL
		LoadDLLs(pApp, &szList);
		
		((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.RemoveAll();
		((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.AddTail(&szList);
		szList.RemoveAll();
	}	
}

//�رնԻ���
void CPlugInDlg::OnBtnclose() 
{
	OnCancel();
}
