
// RegTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RegTest.h"
#include "RegTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRegTestDlg �Ի���


CRegTestDlg::CRegTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRegTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATE_STRING_KEY, &CRegTestDlg::OnBnClickedButtonCreateStringKey)
	ON_BN_CLICKED(IDC_BUTTON_DELSUBKEY, &CRegTestDlg::OnBnClickedButtonDelsubkey)
	ON_BN_CLICKED(IDC_BUTTON_CREATESTRINGKEY, &CRegTestDlg::OnBnClickedButtonCreatestringkey)
	ON_BN_CLICKED(IDC_BUTTON_CREATEDWORDKEY, &CRegTestDlg::OnBnClickedButtonCreatedwordkey)
	ON_BN_CLICKED(IDC_BUTTON_CREATEBINARYKEY, &CRegTestDlg::OnBnClickedButtonCreatebinarykey)
	ON_BN_CLICKED(IDC_BUTTON_DELKEY, &CRegTestDlg::OnBnClickedButtonDelkey)
	ON_BN_CLICKED(IDC_BUTTON_GETSTRINGVALUE, &CRegTestDlg::OnBnClickedButtonGetstringvalue)
	ON_BN_CLICKED(IDC_BUTTON_GETDWORDVALUE, &CRegTestDlg::OnBnClickedButtonGetdwordvalue)
	ON_BN_CLICKED(IDC_BUTTON_GETBINARYVALUE, &CRegTestDlg::OnBnClickedButtonGetbinaryvalue)
	ON_BN_CLICKED(IDC_BUTTON_GETBINARYSTRINGVALUE, &CRegTestDlg::OnBnClickedButtonGetbinarystringvalue)
	ON_BN_CLICKED(IDC_BUTTON_BACKUP, &CRegTestDlg::OnBnClickedButtonBackup)
	ON_BN_CLICKED(IDC_BUTTON_RESTOREKEY, &CRegTestDlg::OnBnClickedButtonRestorekey)
END_MESSAGE_MAP()


// CRegTestDlg ��Ϣ�������

BOOL CRegTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_keyOpeate.selectRootKey(1);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRegTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRegTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRegTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegTestDlg::OnBnClickedButtonCreateStringKey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString value;
	GetDlgItemText(IDC_CREATE_STRING_KEY, value);
	if (value.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	if (TRUE == m_keyOpeate.createSubKey(path, "test"))
	{
		AfxMessageBox(L"�����ɹ�!");
		
	}
	else
	{
		AfxMessageBox(L"����ʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonDelsubkey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString value;
	GetDlgItemText(IDC_DELSUBKEY, value);
	if (value.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	if (TRUE == m_keyOpeate.deleteSubKey(path, "test"))
	{
		AfxMessageBox(L"ɾ���ɹ�!");

	}
	else
	{
		AfxMessageBox(L"ɾ��ʧ��!");
	}
	//CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonCreatestringkey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key, value;
	GetDlgItemText(IDC_CREATE_STRINGKEY, key);
	GetDlgItemText(IDC_CREATE_STRINGVALUE, value);

	if (value.IsEmpty() || key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.createKeyValue(path, T2A(key), T2A(value)))
	{
		AfxMessageBox(L"�����ɹ�!");

	}
	else
	{
		AfxMessageBox(L"����ʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonCreatedwordkey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key;
	int value;
	GetDlgItemText(IDC_CREATE_DWORDKEY, key);
	value = GetDlgItemInt(IDC_CREATE_DWORDVALUE);//��������ͻ��߿�ֵΪ0
	if (key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}
	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.createKeyValue(path, T2A(key), (DWORD)value))
	{
		AfxMessageBox(L"�����ɹ�!");

	}
	else
	{
		AfxMessageBox(L"����ʧ��!");
	}
	CDialog::OnOK();
	return;

}


void CRegTestDlg::OnBnClickedButtonCreatebinarykey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key;
	GetDlgItemText(IDC_CREATE_BINARYKEY, key);
	BYTE value[] = {02, 23, 45, 9};//�ɵ�λ����λ
	if (key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}
	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.createKeyValue(path, T2A(key), value))
	{
		AfxMessageBox(L"�����ɹ�!");

	}
	else
	{
		AfxMessageBox(L"����ʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonDelkey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString value;
	GetDlgItemText(IDC_DELKEY, value);
	if (value.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	if (TRUE == m_keyOpeate.deleteKeyValue(path, "deleteKey"))
	{
		AfxMessageBox(L"ɾ���ɹ�!");

	}
	else
	{
		AfxMessageBox(L"ɾ��ʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetstringvalue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key;
	std::string stringValue;
	GetDlgItemText(IDC_GETSTRINGVALUE, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.getKeyValue(path, T2A(key), stringValue))
	{
		AfxMessageBox(CString(stringValue.c_str()));
	}
	else
	{
		AfxMessageBox(L"��ȡʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetdwordvalue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key;
	DWORD dwValue;
	GetDlgItemText(IDC_GETDWORDKEY, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.getKeyValue(path, T2A(key), dwValue))
	{
		CString value;
		value.Format(_T("%d"), dwValue);
		AfxMessageBox(value);
	}
	else
	{
		AfxMessageBox(L"��ȡʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetbinaryvalue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key;
	BYTE value[64] = {0};
	GetDlgItemText(IDC_GETDBINARYKEY, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.getKeyValue(path, T2A(key), value))
	{
		value;
		AfxMessageBox(L"��ȡ�ɹ�!");
	}
	else
	{
		AfxMessageBox(L"��ȡʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetbinarystringvalue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString key;
	std::string value;
	GetDlgItemText(IDC_GETDBINARSTRINGYKEY, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.getKeyValueEx(path, T2A(key), value))
	{
		AfxMessageBox(CString(value.c_str()));
	}
	else
	{
		AfxMessageBox(L"��ȡʧ��!");
	}
	CDialog::OnOK();
}


void CRegTestDlg::OnBnClickedButtonBackup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	GetDlgItemText(IDC_EDIT_BACKUPNAME, name);
	if (name.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.backupKey(path, T2A(name)))
	{
		AfxMessageBox(L"���ݳɹ�!");
	}
	else
	{
		AfxMessageBox(L"����ʧ��!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonRestorekey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	GetDlgItemText(IDC_EDIT_RESTORENAME, name);
	if (name.IsEmpty())
	{
		AfxMessageBox(L"���벻��Ϊ��!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CStringתchar*
	if (TRUE == m_keyOpeate.restoreKey(path, T2A(name), 1))
	{
		AfxMessageBox(L"��ԭ�ɹ�!");
	}
	else
	{
		AfxMessageBox(L"��ԭʧ��!");
	}
	CDialog::OnOK();
	return;
}
