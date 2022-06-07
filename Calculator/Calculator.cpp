#include "Calculator.h"

wxIMPLEMENT_APP(Calculator);

Calculator::Calculator() {}

Calculator::~Calculator() {}


bool Calculator::OnInit() {

	CalcFrame = new CalcForm();
	CalcFrame->Show();
	return true;
}
