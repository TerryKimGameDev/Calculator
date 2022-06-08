#include "CalcPanel.h"
#include "CalcButton.h"

wxBEGIN_EVENT_TABLE(CalcPanel, wxPanel)
EVT_BUTTON(21, onbttnclicked)

wxEND_EVENT_TABLE()

using namespace std;
CalcPanel::CalcPanel(wxWindow* parent) : wxPanel(parent) {

	wxFont font(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	this->SetFont(font);
	this->SetBackgroundColour(wxColor(235, 235, 222));

	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);

	mtxtCnt = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, 40));
	mtxtCnt->SetFont(font);

	boxsizer->Add(mtxtCnt, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

	numgrid = new wxGridSizer(6, 4, 5, 5);

	CalcButton* nums[10];
	for (int i = 0; i < 10; i++)
	{
		nums[i] = new CalcButton(this, i, to_string(i));
		nums[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcPanel::onbttnclicked, this);
	}

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
	numgrid->Add(nums[9], 0, wxEXPAND);
	numgrid->Add(nums[8], 0, wxEXPAND);
	numgrid->Add(nums[7], 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 11, "="), 0, wxEXPAND);
	numgrid->Add(nums[6], 0, wxEXPAND);
	numgrid->Add(nums[5], 0, wxEXPAND);
	numgrid->Add(nums[4], 0, wxEXPAND);
	numgrid->Add(new CalcButton(this, 10, "-"), 0, wxEXPAND);
	numgrid->Add(nums[3], 0, wxEXPAND);
	numgrid->Add(nums[2], 0, wxEXPAND);
	numgrid->Add(nums[1], 0, wxEXPAND);
	numgrid->Add(nums[0], 0, wxEXPAND);


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
	int eventer = -1;
	int e = evt.GetId();
	if (e < 10)
	{
		eventer = 0;
	}
	else if (e == 21)
	{
		eventer = 1;
	}
	switch (eventer)
	{
	case 0:
	{
		mtxtCnt->AppendText(to_string(evt.GetId()));
		break;
	}
	case 1:
	{
		wxString s = mtxtCnt->GetValue();
		if (s[0] != '-')
		{
			mtxtCnt->SetLabelText("-" + s);
		}
		break;
	}
	case -1:
		break;
	}

	evt.Skip();
}