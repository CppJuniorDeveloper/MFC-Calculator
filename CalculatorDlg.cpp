// CalculatorDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
 


//                      TASK LIST                          //
//                                                         //
// Добавить Журнал Вычислений                              //



// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CCalculatorDlg



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CCalculatorDlg::~CCalculatorDlg()
{
	// добавление времени финиша в журнал событий
	auto finish = std::chrono::system_clock::now();
	std::time_t finish_time = std::chrono::system_clock::to_time_t(finish);
	std::string finish_msg = "Finish: ";
	addToFile('\n' + finish_msg + std::ctime(&finish_time));
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CCalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CCalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CCalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CCalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CCalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CCalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CCalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CCalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CCalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_ADD, &CCalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CCalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MULT, &CCalculatorDlg::OnBnClickedMult)
	ON_BN_CLICKED(IDC_DIV, &CCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_PNT, &CCalculatorDlg::OnBnClickedPnt)
	ON_BN_CLICKED(IDC_EQ, &CCalculatorDlg::OnBnClickedEq)
	ON_BN_CLICKED(IDC_DEL, &CCalculatorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_CE, &CCalculatorDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_C, &CCalculatorDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_PC, &CCalculatorDlg::OnBnClickedPc)
	ON_BN_CLICKED(IDC_DEGREE, &CCalculatorDlg::OnBnClickedDegree)
	ON_BN_CLICKED(IDC_FACT, &CCalculatorDlg::OnBnClickedFact)
	ON_BN_CLICKED(IDC_SWAP, &CCalculatorDlg::OnBnClickedSwap)
	ON_BN_CLICKED(IDC_SQRT, &CCalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_LOG, &CCalculatorDlg::OnBnClickedLog)
	ON_BN_CLICKED(IDC_MCLEAR, &CCalculatorDlg::OnBnClickedMclear)
	ON_BN_CLICKED(IDC_MREAD, &CCalculatorDlg::OnBnClickedMread)
	ON_BN_CLICKED(IDC_MSAVE, &CCalculatorDlg::OnBnClickedMsave)
	ON_BN_CLICKED(IDC_MADD, &CCalculatorDlg::OnBnClickedMadd)
	ON_BN_CLICKED(IDC_MSUB, &CCalculatorDlg::OnBnClickedMsub)
END_MESSAGE_MAP()


// Обработчики сообщений CCalculatorDlg

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// добавление времени старта в журнал событий
	auto start = std::chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	std::string start_msg = "Start: ";
	addToFile('\n' + start_msg + std::ctime(&start_time));

	// экран
	fieldStatic = (CStatic*)GetDlgItem(IDC_STATIC);

	// поля ввода-вывода
	INPOUT = (CStatic*)GetDlgItem(IDC_INPOUT);

	// индикатор памяти
	MEMORY_INDICATOR = (CStatic*)GetDlgItem(IDC_MEM_IND);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// функция подсчитывающая факториал числа
double CCalculatorDlg::factorial(double num)
{
	std::string ERROR__FACTORIAL_INIT = "Ошибка вызова функции факториала";

	if (num > 170) return INFINITY;
	int new_num = (long int)num;
	if (num < 0 || num - new_num != 0) {
		AfxMessageBox(_T("Функция факториала определена только на множестве натуральных чисел!"));
		addToFile("Error: " + ERROR__FACTORIAL_INIT);
		flagError = true;
		return -1;
	}
	else if (num == 0 || num == 1) return 1;
	return num * factorial(num - 1);
}

// функция привродящая класс std::string к типу double
double CCalculatorDlg::stod_(std::string& str)
{
	double new_double = 0;

	if (str == "inf") {
		new_double = INFINITY;
		return new_double;
	}

	bool isFrac = false;
	int div = 1;
	int sign = 1;
	auto it = str.begin();
	for (it; it != str.end(); it++) {
		if (*it == '-') {
			sign *= -1;
			continue;
		}
		double digit = *it - '0';
		if (*it == '.') {
			isFrac = true;
			break;
		}
		new_double *= 10;
		new_double += digit;
	}
	if (isFrac) {
		it++;
		for (it; it != str.end(); it++) {
			double digit = *it - '0';
			div *= 10;
			new_double += (digit / div);
		}
	}

	return new_double * sign;
}

// функция приводящая тип double к классу CString
void CCalculatorDlg::dtocstr_(double& num, CString* CStr)
{
	std::string New_Str = std::to_string(num);
	while (New_Str.back() == '0') {
		New_Str.pop_back();
	}
	if (New_Str.back() == '.') {
		New_Str.pop_back();
	}
	for (int i = 0; i < New_Str.size(); i++) {
		if (New_Str[i] == '.') {
			New_Str[i] = ',';
			break;
		}
	}
	*CStr = New_Str.c_str();
}

// функция считывающая числа
void CCalculatorDlg::GetINPOUTData(CString& CStr)
{
	std::string str;
	CStr_to_str(CStr, &str);
	if (!operation.has_value()) {
		num1 = stod_(str);

	}
	else { num2 = stod_(str);
	
	}

	if (lst_op.has_value()) {
		num2 = lst_num2;
	}
}

// функция приводящая класс CString к калссу std::string
void CCalculatorDlg::CStr_to_str(CString& CStr, std::string* str)
{
	for (int i = 0; i < CStr.GetLength(); i++)
	{

		// меняем запятую на точку
		if (CStr[i] == ',') {
			*str += '.';
			continue;
		}
		*str += CStr[i];
	}
}

// процессор калькулятора
void CCalculatorDlg::Calculate(double* res)
{
	std::string ERROR__NaN = "Неопределённость!";
	std::string ERROR__DIVIDING_BY_ZERO = "Деление на 0!";
	
	CString NaN(ERROR__NaN.c_str());
	CString DIVIDING_BY_ZERO(ERROR__DIVIDING_BY_ZERO.c_str());

	char oper = operation.value();
	switch (oper) {
	case '+':
		*res = num1 + num2;
		break;
	case '-':
		if (num1 == INFINITY && num2 == INFINITY) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		*res = num1 - num2;
		break;
	case '*':
		if ((num1 == 0 && num2 == INFINITY) ||
			(num1 == INFINITY && num2 == 0)) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		*res = num1 * num2;
		break;
	case '/':
		if (num2 == 0) {
			AfxMessageBox(DIVIDING_BY_ZERO);
			addToFile("Error: " + ERROR__DIVIDING_BY_ZERO);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num1 == INFINITY && num2 == INFINITY) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		*res = num1 / num2;
		break;
	case '%':
		*res = num1 / 100 * num2;
		break;
	case '^':
		if (num1 == 0 && num2 == 0) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num1 == INFINITE && num2 == 0) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num1 == 0 && num2 < 0) {
			AfxMessageBox(DIVIDING_BY_ZERO);
			addToFile("Error: " + ERROR__DIVIDING_BY_ZERO);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num1 < 0 && num2 != round(num2)) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num1 == 1 && num2 == INFINITY) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		*res = pow(num1, num2);
		break;
	case 's':
		if (num1 < 0) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		*res = pow(num1, 1 / num2);
		break;
	case 'l':
		if (num1 < 0) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num2 < 0) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num2 == 1) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		if (num1 == 0 && num2 == 0) {
			AfxMessageBox(NaN);
			addToFile("Error: " + ERROR__NaN);
			flagError = true;
			is_num1 = false;
			break;
		}
		*res = log(num1) / log(num2);
		break;
	}
}

// функция выводящая результат вычислений в поле ввода-вывода
void CCalculatorDlg::DisplayResult(double& res)
{
	// если нет ошибок
	if (!flagError) {
		if (!lst_op.has_value()) {
			lst_num2 = num2;
			num2 = 0;
		}
		else { num2 = lst_num2; }
		num1 = res;
		// преобразуем число в стдстринг
		std::string resstr = std::to_string(res);
		// меняем точку на запятую
		auto idx = resstr.find('.');
		if (idx != std::string::npos) {
			resstr[idx] = ',';
		}
		// удаление лишних нулей с конца
		while (resstr.back() == '0') {
			resstr.pop_back();
		}
		// удаление лишней запятой
		if (resstr.back() == ',') {
			resstr.pop_back();
			flagPoint = false;
		}
		else {
			flagPoint = true;
		}
		// преобразуем стдстрин в систринг
		CString resCstr(resstr.c_str());
		// задаем текст полю ввода
		INPOUT->SetWindowTextW(resCstr);
		if (operation.has_value()) {
			lst_op = operation;
		}
		operation.reset();
	}
}

// функция очищающая строку типа CString
void CCalculatorDlg::Clear(CString* CStr)
{
	CStr->Delete(0, CStr->GetLength());
}

// функция обрабатывающая операцию факториала
void CCalculatorDlg::solveFactorial(CString& CStr)
{
	std::string str;
	double num;
	CStr_to_str(CStr, &str);
	num = factorial(stod_(str));
	if (num == -1) {
		operation.reset();
		return;
	}
	CStr += operation.value();
	CStr += _T(" =");
	fieldStatic->SetWindowText(CStr);
	DisplayResult(num);
	fileWrite(false);
}

// функция обрабатывающая нажатие на кнопу с числом
void CCalculatorDlg::addNumbers(int ButtonName)
{
	if (operation.has_value()) {
		NUMBUTTON_isClicked = true;
	}

	// получить число с кнопки
	CString numberButton;
	GetDlgItemText(ButtonName, numberButton);

	// получить текст из поля ввода
	CString inpout;
	INPOUT->GetWindowText(inpout);

	// очистить строку если там ноль
	if (inpout.GetLength() == 1 && inpout[0] == '0') {
			inpout.Delete(0, 1);
	}

	// очистить строку если там бесконечность
	if (inpout == L"inf") {
		inpout.Delete(0, 3);
	}

	// стираем текст из поля ввода для ввода вторго числа
	if (operation.has_value() && num1IsInit) {
		INPOUT->SetWindowTextW(_T(" "));
		Clear(&inpout);
		num1IsInit = false;
	}

	// добавляем в строку число с кнопки
	inpout += numberButton;

	// задать текст экрану
	INPOUT->SetWindowText(inpout);

	// считываем числа
	GetINPOUTData(inpout);

}

// функция записи в журнал событий
void CCalculatorDlg::fileWrite(bool isMemory)
{
	if (flagError) return;
	std::ofstream FILE;
	FILE.open(PATH, std::ofstream::app);
	if (!FILE.is_open()) return;
	std::string FILEDATA;
	CString Screen, inpout, DATA;
	fieldStatic->GetWindowText(Screen);
	INPOUT->GetWindowText(inpout);
	if (!isMemory) {
		DATA = Screen + _T(" ") + inpout;
	}
	else {
		dtocstr_(MEMORY, &DATA);
		DATA = _T("Memory: ") + DATA;
	}
	CStr_to_str(DATA, &FILEDATA);
	FILE << FILEDATA << '\n';
	FILE.close();
}

// функция добавления в журнал событий
void CCalculatorDlg::addToFile(std::string& msg)
{
	std::ofstream FILE;
	FILE.open(PATH, std::ofstream::app);
	if (!FILE.is_open()) return;
	FILE << msg << '\n';
	FILE.close();
}

// кнопка "1"
void CCalculatorDlg::OnBnClicked1()
{
	addNumbers(IDC_1);
}

// кнопка "2"
void CCalculatorDlg::OnBnClicked2()
{
	addNumbers(IDC_2);
}

// кнопка "3"
void CCalculatorDlg::OnBnClicked3()
{
	addNumbers(IDC_3);
}

// кнопка "4"
void CCalculatorDlg::OnBnClicked4()
{
	addNumbers(IDC_4);
}

// кнопка "5"
void CCalculatorDlg::OnBnClicked5()
{
	addNumbers(IDC_5);
}

// кнопка "6"
void CCalculatorDlg::OnBnClicked6()
{
	addNumbers(IDC_6);
}

// кнопка "7"
void CCalculatorDlg::OnBnClicked7()
{
	addNumbers(IDC_7);
}

// кнопка "8"
void CCalculatorDlg::OnBnClicked8()
{
	addNumbers(IDC_8);
}

// кнопка "9"
void CCalculatorDlg::OnBnClicked9()
{
	addNumbers(IDC_9);
}

// кнопка "0"
void CCalculatorDlg::OnBnClicked0()
{
	addNumbers(IDC_0);
}

// функция обрабатывающая нажатие на кнопу с операцией
void CCalculatorDlg::addOperation(int ButtonName)
{
	// удаление памяти операций
	lst_op.reset();
	lst_num2 = 0;

	// получить операцию с кнопки
	CString operButton;
	GetDlgItemText(ButtonName, operButton);

	if (operButton == _T("sqrt")) {
		operButton = 's';
	}
	if (operButton == _T("log")) {
		operButton = 'l';
	}

	// получить текст с экрана
	CString Screen;
	fieldStatic->GetWindowText(Screen);

	num1IsInit = true;
	flagPoint = false;
	flagError = false;

	// очистить строку если там бесконечность
	if (Screen == L"inf") {
		Screen.Delete(0, 3);
		fieldStatic->SetWindowTextW(_T("0"));
		return;
	}

	// если уже была какая-то операция, удаляем её
	if (operation.has_value()) {
		if (NUMBUTTON_isClicked) {
			if (operButton == '%') {
				std::string str;
				double res;
				num2 = num1 * num2 / 100;
				CString NUM;
				dtocstr_(num2, &NUM);
				INPOUT->SetWindowTextW(NUM);	
				return;
			}
			else if (operButton == '!') {
				std::string str;
				double res;
				num2 = factorial(num2);
				CString NUM;
				dtocstr_(num2, &NUM);
				INPOUT->SetWindowTextW(NUM);
				return;
			}
			OnBnClickedEq();
			lst_op.reset();
			lst_num2 = 0;
			num2 = 0;
			fieldStatic->GetWindowText(Screen);
		}
		else {
			Screen.Delete(Screen.GetLength() - 3, 3);
		}
	}

	// сохраняем операцию
	operation = operButton[0];
	NUMBUTTON_isClicked = false;

	// удоляем предыдущее
	Clear(&Screen);

	// добавляем первое число на экран
	CString number;
	dtocstr_(num1, &number);
	Screen += number;

	if (operButton == '!') {
		solveFactorial(Screen);
		return;
	}

	is_num1 = false;

	if (operButton == 's') {
		operButton = _T(" ") + operButton + _T("qrt") + _T(" ");
		Screen += operButton;
		fieldStatic->SetWindowText(Screen);
		return;
	}
	if (operButton == 'l') {
		operButton = _T(" ") + operButton + _T("og") + _T(" ");
		Screen += operButton;
		fieldStatic->SetWindowText(Screen);
		return;
	}

	// добавляем операцию к строке
	operButton = _T(" ") + operButton + _T(" ");
	Screen += operButton;

	// задать текст экрану
	fieldStatic->SetWindowText(Screen);
}

// кнопка "+"
void CCalculatorDlg::OnBnClickedAdd()
{
	addOperation(IDC_ADD);
}

// кнопка "-"
void CCalculatorDlg::OnBnClickedSub()
{
	addOperation(IDC_SUB);
}

// кнопка "*"
void CCalculatorDlg::OnBnClickedMult()
{
	addOperation(IDC_MULT);
}

// кнопка "/"
void CCalculatorDlg::OnBnClickedDiv()
{
	addOperation(IDC_DIV);
}

// кнопка ","
void CCalculatorDlg::OnBnClickedPnt()
{
	if (operation.has_value()) {
		NUMBUTTON_isClicked = true;
	}

	// выполняем, если не было запятой
	if (!flagPoint) {
		// получить текст из поля ввода
		CString textStatic;
		INPOUT->GetWindowText(textStatic);

		// добавляем запятую
		textStatic += ",";

		// задать текст полю ввода
		INPOUT->SetWindowText(textStatic);
		flagPoint = true;
	}
	
}

// функция обрабатывающая нажатие на кнопу "="
void CCalculatorDlg::OnBnClickedEq()
{
	is_num1 = true;

	// считываем текст с экрана
	CString Screen;
	fieldStatic->GetWindowText(Screen);

	// считываем данные с поля ввода
	CString inpout;
	INPOUT->GetWindowText(inpout);

	if (flagError) {
		CString NEWNUM;
		dtocstr_(num1, &NEWNUM);
		Screen = NEWNUM + _T(" ") + operation.value() + _T(" ");
	}

	flagError = false;
	// повторная операция при повторном нажатии равно
	if (lst_op.has_value()) {
		operation = lst_op;
		Clear(&Screen);
		CString NUM;
		dtocstr_(num1, &NUM);
		if (lst_op.value() == 's') {
			Screen = NUM + _T(" ") + lst_op.value() + _T("qrt") + _T(" ");
		}
		else if (lst_op.value() == 'l') {
			Screen = NUM + _T(" ") + lst_op.value() + _T("og") + _T(" ");
		}
		else {
			Screen = NUM + _T(" ") + lst_op.value() + _T(" ");
		}
	}

	GetINPOUTData(inpout);

	if (lst_op.has_value() && lst_op.value() == '!') {
		solveFactorial(inpout);
		return;
	}

	// если просто нажать равно
	if (!operation.has_value() && !lst_op.has_value()) {
		inpout += _T(" =");
		fieldStatic->SetWindowTextW(inpout);
		DisplayResult(num1);
		fileWrite(false);
		return;
	}

	// добавляем второе число на экран
	CString number;
	dtocstr_(num2, &number);
	if (num2 >= 0) {
		Screen += number + _T(" =");
	}
	else {
		Screen += _T("(") + number + _T(")") + _T(" =");
	}

	fieldStatic->SetWindowTextW(Screen);

	std::string str;
	double res = 0;

	// вычисления
	Calculate(&res);
	// отображение реультата
	DisplayResult(res);
	fileWrite(false);
}

// функция удаляющая символы поля ввода-вывода
void CCalculatorDlg::OnBnClickedDel()
{
	if (operation.has_value()) {
		NUMBUTTON_isClicked = true;
	}

	// считываем текст с экрана
	CString Screen;
	INPOUT->GetWindowText(Screen);

	// очистить строку если там бесконечность
	if (Screen == L"inf") {
		Screen.Delete(0, 3);
	}

	if (Screen.GetLength() == 1 && Screen[0] == '0') return;

	// удаляем последний элемент
	if (Screen.GetLength() != 1) {
		if (Screen[Screen.GetLength() - 1] == ',') {
			flagPoint = false;
		}
		Screen.Delete(Screen.GetLength() - 1);
		CString CStr;
		std::string str;
		if (is_num1) {
			dtocstr_(num1, &CStr);
			CStr_to_str(CStr, &str);
			str.pop_back();
			num1 = stod_(str);
			if (str.size() == 1 && str[0] == '-') {
				Screen = _T("0");
				if (is_num1) num1 = 0;
				else num2 = 0;
			}
		}
		else {
			dtocstr_(num2, &CStr);
			CStr_to_str(CStr, &str);
			str.pop_back();
			num2 = stod_(str);
			if (str.size() == 1 && str[0] == '-') {
				Screen = _T("0");
				if (is_num1) num1 = 0;
				else num2 = 0;
			}
		}
	}
	else {
		Screen = _T("0");
		if (is_num1) num1 = 0;
		else num2 = 0;
	}

	// задаём текст экрану
	INPOUT->SetWindowTextW(Screen);

}

// функция стирающая числа поля ввода-вывода
void CCalculatorDlg::OnBnClickedCe()
{
	if (operation.has_value()) {
		NUMBUTTON_isClicked = true;
	}

	CString inpout(_T("0"));
	INPOUT->SetWindowTextW(inpout);

	if (is_num1) num1 = 0;
	else num2 = 0;

	flagPoint = false;
}

// функция стирающая всё кроме памяти
void CCalculatorDlg::OnBnClickedC()
{
	// удаление памяти операций
	lst_op.reset();
	lst_num2 = 0;
	num2 = 0;

	fieldStatic->SetWindowTextW(_T(""));
	INPOUT->SetWindowTextW(_T("0"));
	operation.reset();
	flagError = false;
	flagPoint = false;
	num1IsInit = false;
	NUMBUTTON_isClicked = false;
	is_num1 = true;
	num1 = 0;
	num2 = 0;
}

// кнопка "%"
void CCalculatorDlg::OnBnClickedPc()
{
	addOperation(IDC_PC);
}

// кнопка "^"
void CCalculatorDlg::OnBnClickedDegree()
{
	addOperation(IDC_DEGREE);
}

// кнопка "!"
void CCalculatorDlg::OnBnClickedFact()
{
	addOperation(IDC_FACT);
}

// функция меняющая знак числа
void CCalculatorDlg::OnBnClickedSwap()
{
	if (operation.has_value()) {
		NUMBUTTON_isClicked = true;
	}

	CString inpout;
	INPOUT->GetWindowText(inpout);

	if (is_num1) {
		if (num1 == 0) return;
		else if (num1 < 0) {
			inpout.Remove(_T('-'));
		}
		else {
			inpout = _T("-") + inpout;
		}
		num1 *= -1;
		INPOUT->SetWindowTextW(inpout);
	}
	else {
		INPOUT->GetWindowText(inpout);
		GetINPOUTData(inpout);
		if (num2 == 0) return;
		else if (num2 < 0) {
			inpout.Remove(_T('-'));
		}
		else {
			inpout = _T("-") + inpout;
		}
		num2 *= -1;
		INPOUT->SetWindowTextW(inpout);
	}
}

// кнопка "sqrt"
void CCalculatorDlg::OnBnClickedSqrt()
{
	addOperation(IDC_SQRT);
}

// кнопка "log"
void CCalculatorDlg::OnBnClickedLog()
{
	addOperation(IDC_LOG);
}

// функция очищения памяти
void CCalculatorDlg::OnBnClickedMclear()
{
	if (MEMORY_isInit) {
		MEMORY = 0;
		MEMORY_isInit = false;
		MEMORY_INDICATOR->SetWindowTextW(_T(""));
		std::string msg = "Memory: Clear";
		addToFile(msg);
	}
}

// функция считывания памяти
void CCalculatorDlg::OnBnClickedMread()
{
	if (MEMORY_isInit) {
		CString NUM;
		dtocstr_(MEMORY, &NUM);
		INPOUT->SetWindowTextW(NUM);
		GetINPOUTData(NUM);
		NUMBUTTON_isClicked = true;
	}
}

// функция сохранения в памяти
void CCalculatorDlg::OnBnClickedMsave()
{
	std::string num;
	CString NUM;
	INPOUT->GetWindowText(NUM);
	CStr_to_str(NUM, &num);
	MEMORY = stod_(num);
	MEMORY_isInit = true;
	MEMORY_INDICATOR->SetWindowTextW(_T("M"));
	fileWrite(true);
}

// функция добавления к памяти
void CCalculatorDlg::OnBnClickedMadd()
{
	std::string num;
	CString NUM;
	INPOUT->GetWindowText(NUM);
	CStr_to_str(NUM, &num);
	MEMORY += stod_(num);
	if (MEMORY == 0) return;
	MEMORY_isInit = true;
	MEMORY_INDICATOR->SetWindowTextW(_T("M"));
	fileWrite(true);
}

// функция вычитания из памяти
void CCalculatorDlg::OnBnClickedMsub()
{
	std::string num;
	CString NUM;
	INPOUT->GetWindowText(NUM);
	CStr_to_str(NUM, &num);
	MEMORY -= stod_(num);
	if (MEMORY == 0) return;
	MEMORY_isInit = true;
	MEMORY_INDICATOR->SetWindowTextW(_T("M"));
	fileWrite(true);
}
