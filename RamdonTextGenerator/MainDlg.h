#pragma once


// MainDlg dialog

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MainDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MainDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	const CString m_num = L"0123456789";
	const CString m_upperAlphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const CString m_lowerAlphabet = L"abcdefghijklmnopqrstuvwxyz";
	const CString m_sign = L"~!@#$%^&*()_-+={[}]|\\:;\"',<.>/?";
private:
	afx_msg void OnBnClickedaddnumbutton();
	afx_msg void OnBnClickedaddlowalpbutton();
	afx_msg void OnBnClickedadduppalpbutton();
	afx_msg void OnBnClickedGenerate();
	afx_msg void OnBnClickedaddsignbutton();
};
