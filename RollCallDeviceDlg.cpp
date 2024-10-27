
// RollCallDeviceDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "RollCallDevice.h"
#include "RollCallDeviceDlg.h"
#include "afxdialogex.h"
#include "AboutDlg.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRollCallDeviceDlg 对话框



CRollCallDeviceDlg::CRollCallDeviceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ROLLCALLDEVICE_DIALOG, pParent)
	, Context(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRollCallDeviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TITLETEXT, TitleText);
	DDX_Control(pDX, IDC_SHOWNUMBER, ShowNumber);
	DDX_Control(pDX, IDC_CONTROL, Control);
	DDX_Text(pDX, IDC_SHOWNUMBER, Context);
}

BEGIN_MESSAGE_MAP(CRollCallDeviceDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONTROL, &CRollCallDeviceDlg::OnBnClickedControl)
	ON_WM_TIMER()
	ON_COMMAND(ID_ABOUT, &CRollCallDeviceDlg::OnAbout)
	ON_MESSAGE(WM_Setting, &CRollCallDeviceDlg::OnSetting)
	ON_COMMAND(ID_32774, &CRollCallDeviceDlg::OnSettingFont)
END_MESSAGE_MAP()


// CRollCallDeviceDlg 消息处理程序

BOOL CRollCallDeviceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	Menu.LoadMenuW(IDR_MENU); // 加载菜单
	SetMenu(&Menu); // 设置菜单

	FontSize = _T("200");
	m_Font.CreatePointFont(_ttoi(FontSize), _T("宋体")); // 设置字体
	UpdateFont(200);

	LowerLimit = 1; // 设置默认下限
	UpperLimit = 49; // 设置默认上限

	gen = std::mt19937(rd()); // 初始化随机数发生器

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRollCallDeviceDlg::OnPaint()
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
HCURSOR CRollCallDeviceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CRollCallDeviceDlg::OnSetting(WPARAM wParam, LPARAM lParam)
{
	Setting* setting = (Setting*)wParam;

	FontSize.Format(_T("%d"), setting->FontSize);
	LowerLimit = setting->LowerLimit;
	UpperLimit = setting->UpperLimit;
	delete setting;

	return LRESULT();
}



void CRollCallDeviceDlg::OnBnClickedControl()
{
	if (!State)
	{
		Control.SetWindowTextW(_T("停止"));
		SetTimer(1, 50, NULL);
		State = true;
	}
	else
	{
		Control.SetWindowTextW(_T("启动"));
		KillTimer(1);
		State = false;
	}
}


void CRollCallDeviceDlg::OnTimer(UINT_PTR nIDEvent)
{
	std::uniform_int_distribution<> distrib(LowerLimit, UpperLimit); // 生成一个在 LowerLimit 到 UpperLimit 之间的均匀分布的随机数

	Context.Format(_T("%d"), distrib(gen));
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CRollCallDeviceDlg::OnAbout()
{
	AboutDlg dlg;
	dlg.DoModal();
}


// 更新字体样式
int CRollCallDeviceDlg::UpdateFont(int Size)
{
	m_Font.DeleteObject();
	m_Font.CreatePointFont(Size, _T("宋体"));

	TitleText.SetFont(&m_Font);
	ShowNumber.SetFont(&m_Font);
	Control.SetFont(&m_Font);
	return 0;
}


void CRollCallDeviceDlg::OnSettingFont()
{
	SettingDlg dlg;

	dlg.FontSize = FontSize;
	dlg.LowerLimit.Format(_T("%d"), LowerLimit);
	dlg.UpperLimit.Format(_T("%d"), UpperLimit);

	if (dlg.DoModal() == IDOK)
	{
		UpdateFont(_ttoi(dlg.FontSize));
	}
}
