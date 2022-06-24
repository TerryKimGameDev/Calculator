#include "CalcButton.h"

//made just to color buttons
using namespace std;
CalcButton::CalcButton(wxWindow* parent, wxWindowID id,const wxString &s) : wxButton(parent, id, s) {

	this->SetLabel(s);
	//wxFont font(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	//this->SetFont(font);
	this->SetBackgroundColour(wxColor(119, 119, 100));
	this->SetForegroundColour(wxColor(79, 71, 71));	
}