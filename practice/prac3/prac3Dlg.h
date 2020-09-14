
// prac3Dlg.h: 헤더 파일
//

#pragma once


// Cprac3Dlg 대화 상자
class Cprac3Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cprac3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRAC3_DIALOG };
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
	int m_A1;
	int m_A2;
	int m_B1;
	int m_B2;
	int m_C1;
	int m_C2;
	int m_D1;
	int m_D2;
	afx_msg void OnBnClickedButtPrint();
	afx_msg void OnBnClickedButtZero();
	afx_msg void OnBnClickedButtExit();
};
