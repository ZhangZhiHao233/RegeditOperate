
// RegTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RegTest.h"
#include "RegTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CRegTestDlg 对话框


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


// CRegTestDlg 消息处理程序

BOOL CRegTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_keyOpeate.selectRootKey(1);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRegTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRegTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegTestDlg::OnBnClickedButtonCreateStringKey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString value;
	GetDlgItemText(IDC_CREATE_STRING_KEY, value);
	if (value.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	if (TRUE == m_keyOpeate.createSubKey(path, "test"))
	{
		AfxMessageBox(L"创建成功!");
		
	}
	else
	{
		AfxMessageBox(L"创建失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonDelsubkey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString value;
	GetDlgItemText(IDC_DELSUBKEY, value);
	if (value.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	if (TRUE == m_keyOpeate.deleteSubKey(path, "test"))
	{
		AfxMessageBox(L"删除成功!");

	}
	else
	{
		AfxMessageBox(L"删除失败!");
	}
	//CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonCreatestringkey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key, value;
	GetDlgItemText(IDC_CREATE_STRINGKEY, key);
	GetDlgItemText(IDC_CREATE_STRINGVALUE, value);

	if (value.IsEmpty() || key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.createKeyValue(path, T2A(key), T2A(value)))
	{
		AfxMessageBox(L"创建成功!");

	}
	else
	{
		AfxMessageBox(L"创建失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonCreatedwordkey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key;
	int value;
	GetDlgItemText(IDC_CREATE_DWORDKEY, key);
	value = GetDlgItemInt(IDC_CREATE_DWORDVALUE);//输入非整型或者空值为0
	if (key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}
	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.createKeyValue(path, T2A(key), (DWORD)value))
	{
		AfxMessageBox(L"创建成功!");

	}
	else
	{
		AfxMessageBox(L"创建失败!");
	}
	CDialog::OnOK();
	return;

}


void CRegTestDlg::OnBnClickedButtonCreatebinarykey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key;
	GetDlgItemText(IDC_CREATE_BINARYKEY, key);
	BYTE value[] = {02, 23, 45, 9};//由低位到高位
	if (key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}
	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.createKeyValue(path, T2A(key), value))
	{
		AfxMessageBox(L"创建成功!");

	}
	else
	{
		AfxMessageBox(L"创建失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonDelkey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString value;
	GetDlgItemText(IDC_DELKEY, value);
	if (value.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	if (TRUE == m_keyOpeate.deleteKeyValue(path, "deleteKey"))
	{
		AfxMessageBox(L"删除成功!");

	}
	else
	{
		AfxMessageBox(L"删除失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetstringvalue()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key;
	std::string stringValue;
	GetDlgItemText(IDC_GETSTRINGVALUE, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.getKeyValue(path, T2A(key), stringValue))
	{
		AfxMessageBox(CString(stringValue.c_str()));
	}
	else
	{
		AfxMessageBox(L"获取失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetdwordvalue()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key;
	DWORD dwValue;
	GetDlgItemText(IDC_GETDWORDKEY, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.getKeyValue(path, T2A(key), dwValue))
	{
		CString value;
		value.Format(_T("%d"), dwValue);
		AfxMessageBox(value);
	}
	else
	{
		AfxMessageBox(L"获取失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetbinaryvalue()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key;
	BYTE value[64] = {0};
	GetDlgItemText(IDC_GETDBINARYKEY, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.getKeyValue(path, T2A(key), value))
	{
		value;
		AfxMessageBox(L"获取成功!");
	}
	else
	{
		AfxMessageBox(L"获取失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonGetbinarystringvalue()
{
	// TODO: 在此添加控件通知处理程序代码
	CString key;
	std::string value;
	GetDlgItemText(IDC_GETDBINARSTRINGYKEY, key);
	if (key.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.getKeyValueEx(path, T2A(key), value))
	{
		AfxMessageBox(CString(value.c_str()));
	}
	else
	{
		AfxMessageBox(L"获取失败!");
	}
	CDialog::OnOK();
}


void CRegTestDlg::OnBnClickedButtonBackup()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	GetDlgItemText(IDC_EDIT_BACKUPNAME, name);
	if (name.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.backupKey(path, T2A(name)))
	{
		AfxMessageBox(L"备份成功!");
	}
	else
	{
		AfxMessageBox(L"备份失败!");
	}
	CDialog::OnOK();
	return;
}


void CRegTestDlg::OnBnClickedButtonRestorekey()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	GetDlgItemText(IDC_EDIT_RESTORENAME, name);
	if (name.IsEmpty())
	{
		AfxMessageBox(L"输入不能为空!");
		return;
	}

	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\test";
	USES_CONVERSION;//CString转char*
	if (TRUE == m_keyOpeate.restoreKey(path, T2A(name), 1))
	{
		AfxMessageBox(L"还原成功!");
	}
	else
	{
		AfxMessageBox(L"还原失败!");
	}
	CDialog::OnOK();
	return;
}
