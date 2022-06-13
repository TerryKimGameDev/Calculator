#pragma once
#include "wx/wx.h"
#include "CalcButton.h"
class ButtonFactory
{
public:
	CalcButton* CreateButton(wxWindow* parent, const wxString& s, wxWindowID id = wxID_ANY);
};

