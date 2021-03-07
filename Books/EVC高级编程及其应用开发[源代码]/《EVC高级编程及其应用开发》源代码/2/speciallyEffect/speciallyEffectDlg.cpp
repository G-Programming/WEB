// speciallyEffectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "speciallyEffect.h"
#include "speciallyEffectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpeciallyEffectDlg dialog

CSpeciallyEffectDlg::CSpeciallyEffectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpeciallyEffectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpeciallyEffectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpeciallyEffectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpeciallyEffectDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpeciallyEffectDlg, CDialog)
	//{{AFX_MSG_MAP(CSpeciallyEffectDlg)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelchangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeciallyEffectDlg message handlers

BOOL CSpeciallyEffectDlg::OnInitDialog()
{
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	//
	CListBox * pListBox;
	pListBox = (CListBox*)GetDlgItem(IDC_LIST);
	pListBox->AddString(_T("ˮƽ����ɨ��"));
    pListBox->AddString(_T("ˮƽ����ɨ��"));
	pListBox->AddString(_T("ˮƽ��Ҷ��"));
	pListBox->AddString(_T("��ֱ��Ҷ��"));
	pListBox->AddString(_T("���Ч��"));


	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CSpeciallyEffectDlg::OnSelchangeList() 
{
	CDC memdc; 
    CBitmap m_bitmap;
	int width;            // λͼ�Ŀ��
	int height;           //λͼ�ĸ߶�
	
    //�õ�λͼ
	m_bitmap.LoadBitmap(IDB_BITMAP1);

	//��û�ͼ������Դ
	CDC *pDC = new CClientDC(this);
	if(!memdc.GetSafeHdc())
	{
		memdc.CreateCompatibleDC(pDC);
		memdc.SelectObject(&m_bitmap);
	}
	//��ȡλͼ��С��Ϣ
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);
	width=bm.bmWidth;
	height=bm.bmHeight;
	
	pDC->Rectangle(0,0,width,height);
	CListBox * pListBox;
	pListBox = (CListBox*)GetDlgItem(IDC_LIST);
	
	int nIndex = pListBox->GetCurSel();
	
	switch(nIndex)
	{
	case 0://ˮƽ����ɨ��
		{
			for(int i=0;i<width;i++)
			{
				pDC->BitBlt(i,0,1,height,&memdc,i,0,SRCCOPY);
				Sleep(1);
			}
			break;
		}
	case 1://ˮƽ����ɨ��
		{
			
			for(int i=width-1;i>=0;i--)
			{
				pDC->BitBlt(i,0,1,height,&memdc,i,0,SRCCOPY);
				Sleep(1);
			}
			break;
		}
	case 2://ˮƽ��Ҷ��
		{
			//ÿ��20���ؿ�
			int num=width/20;
			for(int i=0;i<20;i++)
			{
				//�ֱ�ɨ��ÿ��
				for(int j=0;j<num+1;j++)
				{
					pDC->BitBlt(j*20+i,0,1,height,&memdc,j*20+i,0,SRCCOPY);
					Sleep(1);
					
				}
				Sleep(1);
			}
			break;
		}
	case 3://��ֱ��Ҷ��
		{
			int num=height/20;
			for(int i=0;i<20;i++)
			{
				//�ֱ�ɨ��ÿ��
				for(int j=0;j<num+1;j++)
				{
					pDC->BitBlt(0,j*20+i,width,1,&memdc,0,j*20+i,SRCCOPY);
					Sleep(1);
				}
				Sleep(1);
			}
			break;
		}
	case 4://���Ч��
		{
			for(int i=height-1;i>=0;i--)
			{
				for(int j=0;j<i;j++)
				{
					pDC->BitBlt(0,j,width,1,&memdc,0,i,SRCCOPY);
					Sleep(1);
				}
				Sleep(1);
			}
			break;
		}
	}
	m_bitmap.DeleteObject();
    memdc.DeleteDC();
    delete pDC;

}
