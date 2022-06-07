#include "CalcPanel.h"
#include "CalcButton.h"

wxBEGIN_EVENT_TABLE(CalcPanel, wxPanel)
EVT_BUTTON(10001, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcPanel::CalcPanel(wxWindow *parent): wxPanel(parent) {

	wxFont font(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	this->SetFont(font);
	this->SetBackgroundColour(wxColor(235, 235, 222));

	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);

	numgrid = new wxGridSizer(6, 4, 5, 5);

	//numgrid->Add(new wxButton(this, 30, "Bin"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 30, "Bin"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 31, "Hex"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 32, "Dec"), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	//numgrid->Add(new wxStaticBitmap(this, wxID_ANY, wxBitmap("Minecraft-Characters-PNG.png", wxBITMAP_TYPE_PNG)), 0 , wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 40, "%"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 41, "C"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 20, "+"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 21, "--"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 22, "X"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 23, "/"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 7, "7"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 8, "8"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 9, "9"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 11, "="), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 4, "4"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 5, "5"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 6, "6"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 10, "-"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 1, "1"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 2, "2"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 3, "3"), 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 0, "0"), 0, wxEXPAND);


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