#pragma once
#include "wx/wx.h"
class CalcButton : public wxButton
{
public:
	CalcButton(wxWindow* parent, wxWindowID id, const wxString &s);
public:
	void onbttnclicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

