#include "CalcForm.h"
#include "CalcPanel.h"
wxBEGIN_EVENT_TABLE(CalcForm, wxFrame)
EVT_BUTTON(10001, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcForm::CalcForm() : wxFrame(nullptr, wxID_ANY, "Widgets!", wxPoint(30, 30), wxSize(300, 400)) {
	
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);

	mtxtCnt = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, 40));
	mtxtCnt->SetFont(font);

	boxsizer->Add(mtxtCnt, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

	CalcPanel* cal = new CalcPanel(this);
	boxsizer->Add(cal, 1 ,wxEXPAND);
	SetSizer(boxsizer);

}

CalcForm::~CalcForm() {
}

void CalcForm::onbttnclicked(wxCommandEvent& evt)
{
	//mLst->AppendString(mtxtCnt->GetValue());
	//mtxtCnt->AppendText()
	evt.Skip();
}