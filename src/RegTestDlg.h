
// RegTestDlg.h : ͷ�ļ�
//

#pragma once
#include "RegeditOperate.h"


// CRegTestDlg �Ի���
class CRegTestDlg : public CDialogEx
{
// ����
public:
	CRegTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_REGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CRegeditOperate m_keyOpeate;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
