// AboutDlg.cpp: 实现文件
//

#include "pch.h"
#include "RollCallDevice.h"
#include "afxdialogex.h"
#include "AboutDlg.h"


// AboutDlg 对话框

IMPLEMENT_DYNAMIC(AboutDlg, CDialog)

AboutDlg::AboutDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ABOUT, pParent)
{

}

AboutDlg::~AboutDlg()
{
}

void AboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ABOUTTEXT, AboutText);
}


BEGIN_MESSAGE_MAP(AboutDlg, CDialog)
END_MESSAGE_MAP()


// AboutDlg 消息处理程序


BOOL AboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Font.CreatePointFont(180, _T("宋体"));
	AboutText.SetFont(&m_Font);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
