﻿
// Calculator.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCalculatorApp:
// Сведения о реализации этого класса: Calculator.cpp
//

class CCalculatorApp : public CWinApp
{
public:
	CCalculatorApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorApp theApp;
