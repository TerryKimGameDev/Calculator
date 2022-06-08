#include "CalcForm.h"
wxBEGIN_EVENT_TABLE(CalcForm, wxFrame)
EVT_BUTTON(0, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
CalcForm::CalcForm() : wxFrame(nullptr, wxID_ANY, "Widgets!", wxPoint(30, 30), wxSize(300, 400)) {

	//wxPNGHandler* handler = new wxPNGHandler;
	//wxImage::AddHandler(handler);

	/*wxImage* logo = new wxImage(wxBITMAP("Calc.PNG", wxBITMAP_TYPE_PNG).ConvertToImage());
	logo->Rescale(200,200);
	wxStaticBitmap* image;
	image = new wxStaticBitmap(this, wxID_ANY, *logo);*/

	wxBoxSizer* boxsizer = new wxBoxSizer(wxVERTICAL);
	

	cal = new CalcPanel(this);
	boxsizer->Add(cal, 1 ,wxEXPAND);
	//boxsizer->Add(image, 1, wxEXPAND);
	SetSizer(boxsizer);
	
}

CalcForm::~CalcForm() {
}

void CalcForm::onbttnclicked(wxCommandEvent& evt)
{
	//mLst->AppendString(mtxtCnt->GetValue());
	
	
	evt.Skip();
}