#include "CalcButton.h"

wxBEGIN_EVENT_TABLE(CalcButton, wxButton)
EVT_BUTTON(10001, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcButton::CalcButton(wxWindow* parent, wxWindowID id,const wxString &s) : wxButton(parent, id, s) {

	//wxFont font(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	//this->SetFont(font);
	this->SetBackgroundColour(wxColor(119, 119, 100));
	this->SetForegroundColour(wxColor(79, 71, 71));

	
}

void CalcButton::onbttnclicked(wxCommandEvent& evt)
{
	//mLst->AppendString(mtxtCnt->GetValue());
	//mtxtCnt->AppendText()
	evt.Skip();
}