
// RegTestDlg.h : 头文件
//

#pragma once
#include "RegeditOperate.h"


// CRegTestDlg 对话框
class CRegTestDlg : public CDialogEx
{
// 构造
public:
	CRegTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_REGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CRegeditOperate m_keyOpeate;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCreateStringKey();
	afx_msg void OnBnClickedButtonDelsubkey();
	afx_msg void OnBnClickedButtonCreatestringkey();
	afx_msg void OnBnClickedButtonCreatedwordkey();
	afx_msg void OnBnClickedButtonCreatebinarykey();
	afx_msg void OnBnClickedButtonDelkey();
	afx_msg void OnBnClickedButtonGetstringvalue();
	afx_msg void OnBnClickedButtonGetdwordvalue();
	afx_msg void OnBnClickedButtonGetbinaryvalue();
	afx_msg void OnBnClickedButtonGetbinarystringvalue();
	afx_msg void OnBnClickedButtonBackup();
	afx_msg void OnBnClickedButtonRestorekey();
};
