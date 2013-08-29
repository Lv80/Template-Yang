// ControlData.cpp : implementation file
//

#include "stdafx.h"
#include "TemplateCAD.h"
#include "ControlData.h"
#include "afxdialogex.h"


// CControlData dialog

IMPLEMENT_DYNAMIC(CControlData, CDialogEx)

CControlData::CControlData(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControlData::IDD, pParent)
{

}

CControlData::~CControlData()
{
}

void CControlData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_SINGLE, m_btnModeSingle);
	DDX_Control(pDX, IDC_RADIO_MULTI, m_btnModeMulti);
}

BEGIN_MESSAGE_MAP(CControlData, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_SINGLE, &CControlData::OnClickedRadioSingle)
	ON_BN_CLICKED(IDC_RADIO_MULTI, &CControlData::OnClickedRadioMulti)
	ON_BN_CLICKED(IDC_RADIO_SINGLE_LINE, &CControlData::OnClickedRadioSingleLine)
	ON_BN_CLICKED(IDC_RADIO_SINGLE_RECT, &CControlData::OnClickedRadioSingleRect)
	ON_BN_CLICKED(IDC_RADIO_SINGLE_CIRCLE, &CControlData::OnClickedRadioSingleCircle)
	ON_BN_CLICKED(IDC_CHECK_MULTI_LINE, &CControlData::OnClickedCheckMultiLine)
	ON_BN_CLICKED(IDOK, &CControlData::OnBnClickedOk)
END_MESSAGE_MAP()


// CControlData message handlers

void CControlData::OnClickedRadioSingle()
{
	// TODO: Add your control notification handler code here
	m_DrawMode = CTemplateData::DRAW_SINGLE;

	EnableSingleDraw();
}

void CControlData::OnClickedRadioMulti()
{
	// TODO: Add your control notification handler code here
	m_DrawMode = CTemplateData::DRAW_MULTI;

	EnableMultiDraw();
}

void CControlData::EnableSingleDraw()
{
	m_btnSingleTypeLine.EnableWindow(TRUE);
	m_btnSingleTypeRect.EnableWindow(TRUE);
	m_btnSingleTypeCircle.EnableWindow(TRUE);

	m_btnMultiTypeLine.EnableWindow(FALSE);
	m_btnMultiTypeRect.EnableWindow(FALSE);
	m_btnMultiTypeCircle.EnableWindow(FALSE);
}


void CControlData::EnableMultiDraw()
{
	m_btnSingleTypeLine.EnableWindow(FALSE);
	m_btnSingleTypeRect.EnableWindow(FALSE);
	m_btnSingleTypeCircle.EnableWindow(FALSE);

	m_btnMultiTypeLine.EnableWindow(TRUE);
	m_btnMultiTypeRect.EnableWindow(TRUE);
	m_btnMultiTypeCircle.EnableWindow(TRUE);
}

void CControlData::OnClickedRadioSingleLine()
{
	// TODO: Add your control notification handler code here
	m_DrawType = CTemplateData::DRAW_LINE;
}


void CControlData::OnClickedRadioSingleRect()
{
	// TODO: Add your control notification handler code here
	m_DrawType = CTemplateData::DRAW_RECT;
}


void CControlData::OnClickedRadioSingleCircle()
{
	// TODO: Add your control notification handler code here
	m_DrawType = CTemplateData::DRAW_CIRCLE;
}

void CControlData::OnClickedCheckMultiLine()
{
	// TODO: Add your control notification handler code here
}

void CControlData::CalculateDrawType()
{
	m_DrawType = CTemplateData::DRAW_NONE;

	if( m_DrawMode = CTemplateData::DRAW_SINGLE )
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
		else if( m_btnMultiTypeRect.GetCheck() == BST_CHECKED )
		{
			m_DrawType |= CTemplateData::DRAW_RECT;
		} 
		else if( m_btnMultiTypeCircle.GetCheck() == BST_CHECKED )
		{
			m_DrawType |= CTemplateData::DRAW_CIRCLE;
		} 
	}
}


void CControlData::OnBnClickedOk()
{
	CalculateDrawType();

	CTemplateData::GetInstance()->SetDrawMode(m_DrawMode);
	CTemplateData::GetInstance()->SetDrawType(m_DrawType);

	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
