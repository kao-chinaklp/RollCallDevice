#pragma once
#include "afxdialogex.h"


// SettingDlg 对话框

class SettingDlg : public CDialog
{
	DECLARE_DYNAMIC(SettingDlg)

public:
	SettingDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SettingDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CFont m_Font;
	// 字体大小
	CString FontSize;
	// 下限值
	CString LowerLimit;
	// 上限值
	CString UpperLimit;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CStatic TEXT1;
	CStatic TEXT2;
	CStatic TEXT3;
};
