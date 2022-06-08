#pragma once

#include "wx/wx.h"
class CalcPanel : public wxPanel
{
public:
	CalcPanel(wxWindow* parent);
	~CalcPanel();
public:
	wxTextCtrl* mtxtCnt = nullptr;
	wxGridSizer* numgrid = nullptr;

	void onbttnclicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

};

