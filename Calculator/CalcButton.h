#pragma once
#include "wx/wx.h"
#include <string>
class CalcButton : public wxButton
{
private:
	std::string label;
public:
	CalcButton(wxWindow* parent, wxWindowID id, const wxString &s);

	std::string GetstrLabel();
};

