#pragma once

#include "wx/wx.h"
class CalcForm : public wxFrame
{
public:
	CalcForm();
	~CalcForm();

public:
	wxTextCtrl *mtxtCnt = nullptr;
	wxPanel* mPanel = nullptr;

	void onbttnclicked(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();
};

