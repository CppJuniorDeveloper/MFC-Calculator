// CalculatorDlg.h: файл заголовка

#pragma once
#pragma warning(disable : 4996)
#include <optional>
#include <string>


// Диалоговое окно CCalculatorDlg
class CCalculatorDlg : public CDialogEx
{
// Создание
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// стандартный конструктор
	~CCalculatorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	const std::string PATH = "DEBUG.txt";

	double num1 = 0, num2 = 0, lst_num2 = 0;

	double MEMORY = 0;

	CStatic* fieldStatic;
	CStatic* INPOUT;
	CStatic* MEMORY_INDICATOR;

	std::optional<char> operation;
	std::optional<char> lst_op;

	bool flagPoint = false;
	bool flagError = false;
	bool num1IsInit = false;
	bool is_num1 = true;
	bool NUMBUTTON_isClicked = false;
	bool MEMORY_isInit = false;

	double factorial(double num);
	double stod_(std::string& str);

	void dtocstr_(double& num, CString* CStr);
	void GetINPOUTData(CString& CStr);
	void CStr_to_str(CString& CStr, std::string* str);
	void Calculate(double* res);
	void DisplayResult(double& res);
	void Clear(CString* CStr);

public:
	
	void solveFactorial(CString& CStr);
	void addNumbers(int ButtonName);
	void fileWrite(bool isMemory);
	void addToFile(std::string& msg);

	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();

	void addOperation(int ButtonName);

	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDiv();

	afx_msg void OnBnClickedPnt();
	afx_msg void OnBnClickedEq();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedPc();
	afx_msg void OnBnClickedDegree();
	afx_msg void OnBnClickedFact();
	afx_msg void OnBnClickedSwap();
	afx_msg void OnBnClickedSqrt();
	afx_msg void OnBnClickedLog();

	afx_msg void OnBnClickedMclear();
	afx_msg void OnBnClickedMread();
	afx_msg void OnBnClickedMsave();
	afx_msg void OnBnClickedMadd();
	afx_msg void OnBnClickedMsub();
};
