#pragma once
#include "wx/wx.h"
#include <string>
#include <vector>

using namespace std;
class CalcProcessor
{
private:
	static CalcProcessor*_processor;
	int baseNumber;
	CalcProcessor() {}
public:
	static CalcProcessor* GetInstances();


	CalcProcessor(CalcProcessor& other) = delete;

	void operator=(const CalcProcessor& other) = delete;
	wxString GiveOutput(wxString input);

	int Addition(int x, int y);
	int Subtraction(int x,int y);
	int Multiplication(int x, int y);
	int Division(int x, int y);
	int Modulo(int x, int y);

	void setBaseNumber(int number);

	string GetDecimal();
	string GetHexadecimal();


	string GetBinary();
};

