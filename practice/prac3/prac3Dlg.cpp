
// prac3Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "prac3.h"
#include "prac3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cprac3Dlg 대화 상자



Cprac3Dlg::Cprac3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRAC3_DIALOG, pParent)
	, m_A1(0)
	, m_A2(0)
	, m_B1(0)
	, m_B2(0)
	, m_C1(0)
	, m_C2(0)
	, m_D1(0)
	, m_D2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cprac3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A1, m_A1);
	DDX_Text(pDX, IDC_EDIT_A2, m_A2);
	DDX_Text(pDX, IDC_EDIT_B1, m_B1);
	DDX_Text(pDX, IDC_EDIT_B2, m_B2);
	DDX_Text(pDX, IDC_EDIT_C1, m_C1);
	DDX_Text(pDX, IDC_EDIT_C2, m_C2);
	DDX_Text(pDX, IDC_EDIT_D1, m_D1);
	DDX_Text(pDX, IDC_EDIT_D2, m_D2);
}

BEGIN_MESSAGE_MAP(Cprac3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_PRINT, &Cprac3Dlg::OnBnClickedButtPrint)
	ON_BN_CLICKED(IDC_BUTT_ZERO, &Cprac3Dlg::OnBnClickedButtZero)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &Cprac3Dlg::OnBnClickedButtExit)
END_MESSAGE_MAP()


// Cprac3Dlg 메시지 처리기

BOOL Cprac3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cprac3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cprac3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cprac3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cprac3Dlg::OnBnClickedButtPrint()
{
	UpdateData(TRUE);

	CClientDC dc(this);

	InvalidateRect(NULL, TRUE);
	UpdateWindow();
	int C[4];
	C[0] = m_A1 * m_A2;
	C[1] = m_B1 + m_B2;
	C[2] = m_C1 - m_C2;
	C[3] = m_D1 / m_D2;
	char szText[100];

	int nY = 60;

	for (int i = 0; i <= 3; i++) {
		nY = nY + 40;
		sprintf(szText, "= %d : Result %d", C[i], i+1);
		dc.TextOut(270, nY, szText);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cprac3Dlg::OnBnClickedButtZero()
{
	InvalidateRect(NULL, TRUE);
	UpdateWindow();
	m_A1 = 0;
	m_A2 = 0;
	m_B1 = 0;
	m_B2 = 0;
	m_C1 = 0;
	m_C2 = 0;
	m_D1 = 0;
	m_D2 = 0;
	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cprac3Dlg::OnBnClickedButtExit()
{
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
