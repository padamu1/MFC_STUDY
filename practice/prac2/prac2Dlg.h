﻿
// prac2Dlg.h: 헤더 파일
//

#pragma once


// Cprac2Dlg 대화 상자
class Cprac2Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cprac2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRAC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_A;
	int m_B;
	int m_C;
	int m_D;
	afx_msg void OnBnClickedButtPrint();
	afx_msg void OnBnClickedButtZero();
	afx_msg void OnBnClickedButtExit();
};
