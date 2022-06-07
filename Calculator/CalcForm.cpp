#include "CalcForm.h"

wxBEGIN_EVENT_TABLE(CalcForm, wxFrame)
EVT_BUTTON(10001, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcForm::CalcForm() : wxFrame(nullptr, wxID_ANY, "Widgets!", wxPoint(30, 30), wxSize(400, 525)) {
	
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);

	mtxtCnt = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, 40));
	mtxtCnt->SetFont(font);

	boxsizer->Add(mtxtCnt, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

	numgrid = new wxGridSizer(6, 4, 0, 0);

	numgrid->Add(new wxButton(this, 30, "Bin"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 31, "Hex"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 32, "Dec"), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, -1, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, -1, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, -1, ""), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 40, "%"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "CLEAR"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "+"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "--"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "X"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "/"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "7"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "8"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "9"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "="), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "4"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "5"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "6"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "-"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "1"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "2"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "3"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "0"), 0, wxEXPAND);
	

	boxsizer->Add(numgrid, 1 ,wxEXPAND);
	numgrid->Layout();
	SetSizer(boxsizer);
}

CalcForm::~CalcForm() {
}

void CalcForm::onbttnclicked(wxCommandEvent& evt)
{
	//mLst->AppendString(mtxtCnt->GetValue());
	evt.Skip();
}