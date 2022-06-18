#pragma once
#include "wx/wx.h"
#include "CalcProcessor.h"
class CalcPanel : public wxPanel
{
public:
	CalcPanel(wxWindow* parent);
	~CalcPanel();
public:
	wxTextCtrl* mtxtCnt = nullptr;
	wxGridSizer* numgrid = nullptr;
	CalcProcessor* processor = CalcProcessor::GetInstances();

	void onbttnclicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

};

