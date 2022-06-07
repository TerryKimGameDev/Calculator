#pragma once

#include "wx/wx.h"
#include "CalcForm.h"
class Calculator : public wxApp
{
public:
	Calculator();
	~Calculator();

private:
	CalcForm* CalcFrame = nullptr;

public:
	virtual bool OnInit();
};

