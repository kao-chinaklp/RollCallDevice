
// RollCallDeviceDlg.h: 头文件
//

#pragma once

#include <random>

// CRollCallDeviceDlg 对话框
class CRollCallDeviceDlg : public CDialogEx
{
// 构造
public:
	CRollCallDeviceDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROLLCALLDEVICE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnSetting(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	// 标题文本
	CStatic TitleText;
	// 显示结果
	CEdit ShowNumber;
	// 控制启停
	CButton Control;
	// 字体变量
	CFont m_Font;
	afx_msg void OnBnClickedControl();
	// 判断是否启动
	bool State;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// 文本
	CString Context;
	// 上限
	int UpperLimit;
	// 下限
	int LowerLimit;
	std::random_device rd;  // 从一个随机数发生器上获得一个真正的随机数
	std::mt19937 gen; // gen是一个使用rd()作种子初始化的标准梅森旋转算法的随机数发生器
	// 菜单
	CMenu Menu;
	afx_msg void OnAbout();
	// 更新字体样式
	int UpdateFont(int Size);
	afx_msg void OnSettingFont();
	// 字体大小
	CString FontSize;
};
