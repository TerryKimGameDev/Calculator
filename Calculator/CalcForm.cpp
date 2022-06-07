#include "CalcForm.h"

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

	numgrid = new wxGridSizer(6, 4, 0, 0);

	numgrid->Add(new wxButton(this, 30, "Bin"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 31, "Hex"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 32, "Dec"), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 40, "%"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "CLEAR"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 20, "+"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 21, "--"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 22, "X"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 23, "/"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 7, "7"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 8, "8"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 9, "9"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 11, "="), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 4, "4"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 5, "5"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 6, "6"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 10, "-"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 1, "1"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 2, "2"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 3, "3"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 0, "0"), 0, wxEXPAND);
	

	boxsizer->Add(numgrid, 1 ,wxEXPAND);
	numgrid->Layout();
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