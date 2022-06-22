#include "CalcPanel.h"
#include "ButtonFactory.h"
#include "CalcButton.h"

wxBEGIN_EVENT_TABLE(CalcPanel, wxPanel)
EVT_BUTTON(wxID_ANY, CalcPanel::onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcPanel::CalcPanel(wxWindow* parent) : wxPanel(parent) {

	wxFont font(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	this->SetFont(font);
	this->SetBackgroundColour(wxColor(235, 235, 222));

	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);

	mtxtCnt = new wxTextCtrl(this, wxID_ANY, wxT(""));

	boxsizer->Add(mtxtCnt, 0, wxEXPAND | wxTOP | wxBOTTOM, 4); //note to self this resizes elements that you give it.

	numgrid = new wxGridSizer(6, 4, 5, 5);
	ButtonFactory bf;
	
	numgrid->Add(bf.CreateButton(this, "Bin", 800), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "Hex", 801), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "Dec", 802), 0, wxEXPAND);

	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);
	numgrid->Add(new wxStaticText(this, wxID_ANY, ""), 0, wxEXPAND);

	numgrid->Add(bf.CreateButton(this, "%"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "C", 41), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "+"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "-"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "X"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "/"), 0, wxEXPAND);

	numgrid->Add(bf.CreateButton(this, "9"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "8"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "7"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "=", 200), 0, wxEXPAND);

	numgrid->Add(bf.CreateButton(this, "6"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "5"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "4"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "--", 21), 0, wxEXPAND);

	numgrid->Add(bf.CreateButton(this, "3"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "2"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "1"), 0, wxEXPAND);
	numgrid->Add(bf.CreateButton(this, "0"), 0, wxEXPAND);

	boxsizer->Add(numgrid, 1, wxEXPAND);

	SetSizer(boxsizer);
}

CalcPanel::~CalcPanel() {
}

void CalcPanel::onbttnclicked(wxCommandEvent& evt)
{
	//CalcButton* pButton = dynamic_cast<CalcButton*>(evt.GetEventObject()); //the other way
	int id = evt.GetId();
	switch (id)
	{
	default:
	{
		mtxtCnt->AppendText(this->FindItem(id)->GetLabel());
		break;
	}
	case 21:
	{
		if (!mtxtCnt->IsEmpty())
		{
			wxString s = mtxtCnt->GetValue();
			if (s[0] != '(')
			{
				mtxtCnt->SetLabelText("(~" + s+")");
			}
			else
			{
				s.erase(remove(s.begin(), s.end(), '('), s.end());
				s.erase(remove(s.begin(), s.end(), '~'), s.end());
				s.erase(remove(s.begin(), s.end(), ')'), s.end());
				mtxtCnt->SetLabelText(s);
			}
		}
		else
		{
			mtxtCnt->AppendText('~');
		}
		break;
	}
	case 41:
	{
		mtxtCnt->Clear();
		break;
	}
	case 200:
	{
		mtxtCnt->SetLabel(processor->GiveOutput(mtxtCnt->GetValue()));
		break;
	}
	case 800:
	{
		string s(mtxtCnt->GetValue().c_str());
		processor->setBaseNumber(stoi(s));
		mtxtCnt->SetLabel(processor->GetBinary());
		break;
	}
	case 801:
	{
		string s(mtxtCnt->GetValue().c_str());
		processor->setBaseNumber(stoi(s));
		mtxtCnt->SetLabel(processor->GetHexadecimal());
		break;
	}
	case 802:
	{
		string s(mtxtCnt->GetValue().c_str());
		processor->setBaseNumber(stoi(s));
		mtxtCnt->SetLabel(processor->GetDecimal());
		break;
	}
	case -1:
		break;
	}

	evt.Skip();
}