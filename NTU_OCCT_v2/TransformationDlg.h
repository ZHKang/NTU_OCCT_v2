
#pragma once

// Transformation ��ܤ��

class TransformationDlg : public CDialog
{
	DECLARE_DYNAMIC(TransformationDlg)

public:
	TransformationDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~TransformationDlg();

// ��ܤ�����
	enum { IDD = IDD_Transformation };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedXplus();
	afx_msg void OnBnClickedXminus();
	afx_msg void OnBnClickedYplus();
	afx_msg void OnBnClickedYminus();
	afx_msg void OnBnClickedZplus();
	afx_msg void OnBnClickedZminus();
};
