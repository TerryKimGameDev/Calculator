#pragma once

#include "wx/wx.h"
class CalcForm : public wxFrame
{
public:
	CalcForm();
	~CalcForm();

public:
	wxButton** mNumBttn;
	wxTextCtrl *mtxtCnt = nullptr;
	wxPanel* panel = nullptr;
	wxGridSizer* numgrid = nullptr;

	void onbttnclicked(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();
};

