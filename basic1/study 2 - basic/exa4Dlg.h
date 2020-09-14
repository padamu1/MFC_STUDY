
// exa4Dlg.h: 헤더 파일
//

#pragma once


// Cexa4Dlg 대화 상자
class Cexa4Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cexa4Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXA4_DIALOG };
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
	// EDIT CONTROL
	CString m_A;
	afx_msg void OnBnClickedButtPrint();
	afx_msg void OnBnClickedButtZero();
	afx_msg void OnBnClickedButtExit();
	// 헤더에 실제로 있는 버튼들에 대한 반응들만 제대로 컴파일 되게끔 입력이 되어야 함

};
