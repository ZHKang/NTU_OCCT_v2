// Transformation.cpp : ��@��
//

#include "stdafx.h"
#include "NTU_OCCT_v2.h"
#include "TransformationDlg.h"
#include "afxdialogex.h"

#include "NTU_OCCT_v2Doc.h"


// Transformation ��ܤ��

IMPLEMENT_DYNAMIC(TransformationDlg, CDialog)

TransformationDlg::TransformationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TransformationDlg::IDD, pParent)
{
}

TransformationDlg::~TransformationDlg()
{
		DestroyWindow();
}

void TransformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TransformationDlg, CDialog)
	ON_BN_CLICKED(IDC_Xplus, &TransformationDlg::OnBnClickedXplus)
	ON_BN_CLICKED(IDC_Xminus, &TransformationDlg::OnBnClickedXminus)
	ON_BN_CLICKED(IDC_Yplus, &TransformationDlg::OnBnClickedYplus)
	ON_BN_CLICKED(IDC_Yminus, &TransformationDlg::OnBnClickedYminus)
	ON_BN_CLICKED(IDC_Zplus, &TransformationDlg::OnBnClickedZplus)
	ON_BN_CLICKED(IDC_Zminus, &TransformationDlg::OnBnClickedZminus)
END_MESSAGE_MAP()


// Transformation �T���B�z�`��

BOOL TransformationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}


void TransformationDlg::OnBnClickedXplus()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CNTU_OCCT_v2Doc myNTU;
	int selec = 1;
	//myNTU.TransformationFcn(selec);
	//UpdateData(TRUE);
}


void TransformationDlg::OnBnClickedXminus()
{
}


void TransformationDlg::OnBnClickedYplus()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CNTU_OCCT_v2Doc myNTU;
}


void TransformationDlg::OnBnClickedYminus()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CNTU_OCCT_v2Doc myNTU;
}


void TransformationDlg::OnBnClickedZplus()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CNTU_OCCT_v2Doc myNTU;
}


void TransformationDlg::OnBnClickedZminus()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CNTU_OCCT_v2Doc myNTU;
}
