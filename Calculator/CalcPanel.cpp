#include "CalcPanel.h"

wxBEGIN_EVENT_TABLE(CalcPanel, wxPanel)
EVT_BUTTON(10001, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcPanel::CalcPanel(wxWindow *parent): wxPanel(parent) {

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	this->SetFont(font);
	//mPanel = new wxPanel(this, wxID_ANY, wxPoint(40, 100), wxSize(200,200));
	//mPanel->SetFont(font);

	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);

	numgrid = new wxGridSizer(6, 4, 5, 5);


	numgrid->Add(new wxButton(this, 30, "Bin"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 31, "Hex"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 32, "Dec"), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 40, "%"), 0, wxEXPAND);
	numgrid->Add(new wxButton(this, 41, "C"), 0, wxEXPAND);
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



	boxsizer->Add(numgrid, 1, wxEXPAND);
	numgrid->Layout();
	SetSizer(boxsizer);
}

CalcPanel::~CalcPanel() {
}

void CalcPanel::onbttnclicked(wxCommandEvent& evt)
{
	//mLst->AppendString(mtxtCnt->GetValue());
	//mtxtCnt->AppendText()
	evt.Skip();
}