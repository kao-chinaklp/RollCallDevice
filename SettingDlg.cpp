// SettingDlg.cpp: 实现文件
//

#include "pch.h"
#include "RollCallDevice.h"
#include "afxdialogex.h"
#include "SettingDlg.h"


// SettingDlg 对话框

IMPLEMENT_DYNAMIC(SettingDlg, CDialog)

SettingDlg::SettingDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETTING, pParent)
	, FontSize(_T(""))
	, LowerLimit(_T(""))
	, UpperLimit(_T(""))
{

}

SettingDlg::~SettingDlg()
{
}

void SettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FontSize);
	DDX_Text(pDX, IDC_EDIT2, LowerLimit);
	DDX_Text(pDX, IDC_EDIT3, UpperLimit);
	DDX_Control(pDX, IDC_TEXT1, TEXT1);
	DDX_Control(pDX, IDC_TEXT2, TEXT2);
	DDX_Control(pDX, IDC_TEXT3, TEXT3);
}


BEGIN_MESSAGE_MAP(SettingDlg, CDialog)
	ON_BN_CLICKED(IDOK, &SettingDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SettingDlg 消息处理程序


void SettingDlg::OnBnClickedOk()
{
	Setting* setting = new Setting;
	UpdateData(TRUE);

	setting->FontSize = _ttoi(FontSize);
	setting->LowerLimit = _ttoi(LowerLimit);
	setting->UpperLimit = _ttoi(UpperLimit);

	::SendMessage(this->GetParent()->m_hWnd, WM_Setting, (WPARAM)setting, 0);

	CDialog::OnOK();
}


BOOL SettingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Font.CreatePointFont(_ttoi(FontSize), _T("宋体"));
	GetDlgItem(IDC_EDIT1)->SetFont(&m_Font);
	GetDlgItem(IDC_EDIT2)->SetFont(&m_Font);
	GetDlgItem(IDC_EDIT3)->SetFont(&m_Font);
	TEXT1.SetFont(&m_Font);
	TEXT2.SetFont(&m_Font);
	TEXT3.SetFont(&m_Font);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
