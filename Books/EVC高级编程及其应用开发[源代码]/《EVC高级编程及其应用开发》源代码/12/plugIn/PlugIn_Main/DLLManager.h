// DLLManager.h: interface for the CDLLManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLLMANAGER_H__F429BE7C_DC2F_4878_95C4_7182F54D5D27__INCLUDED_)
#define AFX_DLLMANAGER_H__F429BE7C_DC2F_4878_95C4_7182F54D5D27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDLLManager  
{
public:
	CDLLManager();
	virtual ~CDLLManager();
public:
	//����DLL
	bool LoadDLL(CString szFileName);
	//��ʼ��DLL
	bool InitDLL();
	//�ͷ�DLL
	bool FreeDLL();
	//����ToolBarָ��
	void SetToolBarPointer(CToolBar *pWndToolBar);
	//�����ToolBar�ϵİ�ť�¼�
	bool HandleOnClick();
	//�õ����ͼ��Ͳ������
	bool GetPlugInResources(HICON *hIcon, CString *szLabel);
	//�õ��������
	bool GetDLLName(CString *szName);
 	//�õ������ť��ʶ
	UINT GetToolBarButtonID(); 
	//����DLL�����ļ���
	void SetDLLFileName(CString szFileName);

private:
    //���ڴ洢������ָ��
	CToolBar *m_pwndToolBar;
	//���ڴ洢�����ť��ID
	UINT m_unToolBarID;
public:
	//�洢DLL�������ļ���
	CString m_szDLLFileName;
	//�洢�Ѽ��ص�DLL���
	HINSTANCE m_pDLLhInstance;
	//�洢�����
	CString m_szPlugInName;

};

#endif // !defined(AFX_DLLMANAGER_H__F429BE7C_DC2F_4878_95C4_7182F54D5D27__INCLUDED_)
