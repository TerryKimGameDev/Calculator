#include "ButtonFactory.h"

CalcButton* ButtonFactory::CreateButton(wxWindow* parent, const wxString& s, wxWindowID id) {
	return new CalcButton(parent, id, s);
}