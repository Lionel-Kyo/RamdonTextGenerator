// MainDlg.cpp : implementation file
//

#include "pch.h"
#include "RamdonTextGenerator.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include <time.h>
#include <vector>

BOOL MainDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			HWND hWnd = ::GetFocus();
			int focusID = ::GetDlgCtrlID(hWnd);
			switch (focusID)
			{
			case IDC_Text_Input:
			case IDC_Text_Output:
				return CDialog::PreTranslateMessage(pMsg);
				break;
			case IDC_addNum_button:
				OnBnClickedaddnumbutton();
				break;
			case IDC_add_lowAlp_button:
				OnBnClickedaddlowalpbutton();
				break;
			case IDC_add_uppAlp_button:
				OnBnClickedadduppalpbutton();
				break;
			case IDC_add_sign_button:
				OnBnClickedaddsignbutton();
				break;
			case IDC_Num_text_edit:
			case IDC_Length_edit:
			case IDC_Generate:
				OnBnClickedGenerate();
				break;
			}
			return TRUE;
		}
		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

// MainDlg dialog

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MainDlg, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_addNum_button, &MainDlg::OnBnClickedaddnumbutton)
	ON_BN_CLICKED(IDC_add_lowAlp_button, &MainDlg::OnBnClickedaddlowalpbutton)
	ON_BN_CLICKED(IDC_add_uppAlp_button, &MainDlg::OnBnClickedadduppalpbutton)
	ON_BN_CLICKED(IDC_Generate, &MainDlg::OnBnClickedGenerate)
	ON_BN_CLICKED(IDC_add_sign_button, &MainDlg::OnBnClickedaddsignbutton)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_Num_text_edit)->SetWindowText(L"1");
	GetDlgItem(IDC_Length_edit)->SetWindowText(L"10");
	return TRUE;
}


// MainDlg message handlers


void MainDlg::OnBnClickedaddnumbutton()
{
	CString str;
	GetDlgItem(IDC_Text_Input)->GetWindowText(str);
	if (!str.IsEmpty())str += "\r\n";
	str = str + m_num;
	GetDlgItem(IDC_Text_Input)->SetWindowText(str);
}


void MainDlg::OnBnClickedaddlowalpbutton()
{
	CString str;
	GetDlgItem(IDC_Text_Input)->GetWindowText(str);
	if (!str.IsEmpty())str += L"\r\n";
	str = str + m_lowerAlphabet;
	GetDlgItem(IDC_Text_Input)->SetWindowText(str);
}


void MainDlg::OnBnClickedadduppalpbutton()
{
	CString str;
	GetDlgItem(IDC_Text_Input)->GetWindowText(str);
	if (!str.IsEmpty())str += L"\r\n";
	str = str + m_upperAlphabet;
	GetDlgItem(IDC_Text_Input)->SetWindowText(str);
}

void MainDlg::OnBnClickedaddsignbutton()
{
	CString str;
	GetDlgItem(IDC_Text_Input)->GetWindowText(str);
	if (!str.IsEmpty())str += L"\r\n";
	str = str + m_sign;
	GetDlgItem(IDC_Text_Input)->SetWindowText(str);
}


void MainDlg::OnBnClickedGenerate()
{
	int ranset = (time(0) / clock()) * 11;
	srand(ranset);
	std::vector<CString> text;
	CString str, rantext, cstr_strLength,cstr_numTextLenth;
	int str_length, numTextLenth;
	GetDlgItem(IDC_Text_Input)->GetWindowText(str);
	GetDlgItem(IDC_Length_edit)->GetWindowText(cstr_strLength);
	GetDlgItem(IDC_Num_text_edit)->GetWindowText(cstr_numTextLenth);
	if (str.IsEmpty())return;
	str_length = _wtoi(cstr_strLength);
	numTextLenth = _wtoi(cstr_numTextLenth);
	for (int i = 0; i < numTextLenth; i++)
	{
		for (int k = 0; k < str_length; k++)
		{
			wchar_t temple;
			do
			{
				temple = str[rand() % str.GetLength()];

			} while (temple == '\r' || temple == '\n');
			rantext += temple;
		}
		text.push_back(rantext);
		rantext.Empty();
	}
	for (CString cstr_text : text)
	{
		rantext += cstr_text;
		rantext += L"\r\n";
	}
	GetDlgItem(IDC_Text_Output)->SetWindowText(rantext);
}
