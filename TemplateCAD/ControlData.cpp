// ControlData.cpp : implementation file
//

#include "stdafx.h"
#include "TemplateCAD.h"
#include "ControlData.h"
#include "afxdialogex.h"


// CControlDataDlg dialog

IMPLEMENT_DYNAMIC(CControlDataDlg, CDialogEx)

CControlDataDlg::CControlDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControlDataDlg::IDD, pParent)
{

}

CControlDataDlg::~CControlDataDlg()
{
}

BOOL CControlDataDlg::OnInitDialog()
{
	//和页面交互数据
	CDialog::OnInitDialog();

	CTemplateData::DRAW_MODE drawMode =
		CTemplateData::GetInstance()->GetDrawMode();

	int drawType =
		CTemplateData::GetInstance()->GetDrawType();

	if( drawMode == CTemplateData::DRAW_SINGLE )
	{
		//设置绘画类型
		if( drawType & CTemplateData::DRAW_LINE )
		{
			m_btnSingleTypeLine.SetCheck(true);
		} 
		else if ( drawType & CTemplateData::DRAW_RECT )
		{
			m_btnSingleTypeRect.SetCheck(true);
		}
		else if( drawType & CTemplateData::DRAW_CIRCLE )
		{
			m_btnSingleTypeCircle.SetCheck(true);
		}

		m_btnModeSingle.SetCheck(true);
		SendMessage( WM_COMMAND, m_btnModeSingle.GetDlgCtrlID(), (LONG)GetSafeHwnd() );
	}
	else if( drawMode == CTemplateData::DRAW_MULTI )
	{
		//设置绘画类型
		if( drawType & CTemplateData::DRAW_LINE )
		{
			m_btnMultiTypeLine.SetCheck(true);
		} 
		
		if ( drawType & CTemplateData::DRAW_RECT )
		{
			m_btnMultiTypeRect.SetCheck(true);
		}
		
		if( drawType & CTemplateData::DRAW_CIRCLE )
		{
			m_btnMultiTypeCircle.SetCheck(true);
		}

		m_btnModeMulti.SetCheck(true);
		SendMessage( WM_COMMAND, m_btnModeMulti.GetDlgCtrlID(), (LONG)GetSafeHwnd() );
	}

	return true;
}

void CControlDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_SINGLE, m_btnModeSingle);
	DDX_Control(pDX, IDC_RADIO_MULTI, m_btnModeMulti);

	DDX_Control(pDX, IDC_RADIO_SINGLE_LINE, m_btnSingleTypeLine);
	DDX_Control(pDX, IDC_RADIO_SINGLE_RECT, m_btnSingleTypeRect);
	DDX_Control(pDX, IDC_RADIO_SINGLE_CIRCLE, m_btnSingleTypeCircle);

	DDX_Control(pDX, IDC_CHECK_MULTI_LINE, m_btnMultiTypeLine);
	DDX_Control(pDX, IDC_CHECK_MULTI_RECT, m_btnMultiTypeRect);
	DDX_Control(pDX, IDC_CHECK_MULTI_CIRCLE, m_btnMultiTypeCircle);
}

BEGIN_MESSAGE_MAP(CControlDataDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_SINGLE, &CControlDataDlg::OnClickedRadioSingle)
	ON_BN_CLICKED(IDC_RADIO_MULTI, &CControlDataDlg::OnClickedRadioMulti)
	ON_BN_CLICKED(IDC_RADIO_SINGLE_LINE, &CControlDataDlg::OnClickedRadioSingleLine)
	ON_BN_CLICKED(IDC_RADIO_SINGLE_RECT, &CControlDataDlg::OnClickedRadioSingleRect)
	ON_BN_CLICKED(IDC_RADIO_SINGLE_CIRCLE, &CControlDataDlg::OnClickedRadioSingleCircle)
	ON_BN_CLICKED(IDC_CHECK_MULTI_LINE, &CControlDataDlg::OnClickedCheckMultiLine)
	ON_BN_CLICKED(IDOK, &CControlDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CControlDataDlg message handlers

void CControlDataDlg::OnClickedRadioSingle()
{
	// TODO: Add your control notification handler code here
	m_DrawMode = CTemplateData::DRAW_SINGLE;

	EnableSingleDraw();
}

void CControlDataDlg::OnClickedRadioMulti()
{
	// TODO: Add your control notification handler code here
	m_DrawMode = CTemplateData::DRAW_MULTI;

	EnableMultiDraw();
}

void CControlDataDlg::EnableSingleDraw()
{
	m_btnSingleTypeLine.EnableWindow(TRUE);
	m_btnSingleTypeRect.EnableWindow(TRUE);
	m_btnSingleTypeCircle.EnableWindow(TRUE);

	m_btnMultiTypeLine.EnableWindow(FALSE);
	m_btnMultiTypeRect.EnableWindow(FALSE);
	m_btnMultiTypeCircle.EnableWindow(FALSE);
}


void CControlDataDlg::EnableMultiDraw()
{
	m_btnSingleTypeLine.EnableWindow(FALSE);
	m_btnSingleTypeRect.EnableWindow(FALSE);
	m_btnSingleTypeCircle.EnableWindow(FALSE);

	m_btnMultiTypeLine.EnableWindow(TRUE);
	m_btnMultiTypeRect.EnableWindow(TRUE);
	m_btnMultiTypeCircle.EnableWindow(TRUE);
}

void CControlDataDlg::OnClickedRadioSingleLine()
{
	// TODO: Add your control notification handler code here
	m_DrawType = CTemplateData::DRAW_LINE;
}


void CControlDataDlg::OnClickedRadioSingleRect()
{
	// TODO: Add your control notification handler code here
	m_DrawType = CTemplateData::DRAW_RECT;
}


void CControlDataDlg::OnClickedRadioSingleCircle()
{
	// TODO: Add your control notification handler code here
	m_DrawType = CTemplateData::DRAW_CIRCLE;
}

void CControlDataDlg::OnClickedCheckMultiLine()
{
	// TODO: Add your control notification handler code here
}

void CControlDataDlg::CalculateDrawType()
{
	m_DrawType = CTemplateData::DRAW_NONE;

	if( m_DrawMode == CTemplateData::DRAW_SINGLE )
	{
		if( m_btnSingleTypeLine.GetCheck() == BST_CHECKED )
		{
			m_DrawType = CTemplateData::DRAW_LINE;
		} 
		else if( m_btnSingleTypeRect.GetCheck() == BST_CHECKED )
		{
			m_DrawType = CTemplateData::DRAW_RECT;
		} 
		else if( m_btnSingleTypeCircle.GetCheck() == BST_CHECKED )
		{
			m_DrawType = CTemplateData::DRAW_CIRCLE;
		} 
	}
	else
	{
		if( m_btnMultiTypeLine.GetCheck() == BST_CHECKED )
		{
			m_DrawType |= CTemplateData::DRAW_LINE;
		} 
		
		if( m_btnMultiTypeRect.GetCheck() == BST_CHECKED )
		{
			m_DrawType |= CTemplateData::DRAW_RECT;
		} 
		
		if( m_btnMultiTypeCircle.GetCheck() == BST_CHECKED )
		{
			m_DrawType |= CTemplateData::DRAW_CIRCLE;
		} 
	}
}


void CControlDataDlg::OnBnClickedOk()
{
	CalculateDrawType();

	CTemplateData::GetInstance()->SetDrawMode(m_DrawMode);
	CTemplateData::GetInstance()->SetDrawType(m_DrawType);

	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
