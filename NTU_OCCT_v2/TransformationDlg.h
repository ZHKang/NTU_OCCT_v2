
#pragma once

// Transformation 對話方塊

class TransformationDlg : public CDialog
{
	DECLARE_DYNAMIC(TransformationDlg)

public:
	TransformationDlg(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~TransformationDlg();

// 對話方塊資料
	enum { IDD = IDD_Transformation };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
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
