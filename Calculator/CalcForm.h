#pragma once

#include "wx/wx.h"
#include "CalcPanel.h"
class CalcForm : public wxFrame
{
public:
	CalcForm();
	~CalcForm();

public:
	CalcPanel* cal = nullptr;

	void onbttnclicked(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();
};

