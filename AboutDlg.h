﻿#pragma once
#include "afxdialogex.h"


// AboutDlg 对话框

class AboutDlg : public CDialog
{
	DECLARE_DYNAMIC(AboutDlg)

public:
	AboutDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFont m_Font;
	// 关于
	CStatic AboutText;
	// 链接
	CMFCLinkCtrl Link;
};
