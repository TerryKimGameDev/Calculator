#include "CalcProcessor.h"
#include "IBaseCommand.h"

struct AddCommand : public IBaseCommand
{
private:
	CalcProcessor* _proc = nullptr;
	int _x = 0;
	int _y = 0;
public:
	AddCommand(CalcProcessor* proc, int x, int y) {
		_proc = proc;
		_x = x;
		_y = y;
	}
	void Execute() {
		_proc->setBaseNumber(_proc->Addition(_x, _y));
	}
};
struct SubtractCommand : public IBaseCommand
{
private:
	CalcProcessor* _proc = nullptr;
	int _x = 0;
	int _y = 0;
public:
	SubtractCommand(CalcProcessor* proc, int x, int y) {
		_proc = proc;
		_x = x;
		_y = y;
	}
	void Execute() {
		_proc->setBaseNumber(_proc->Subtraction(_x, _y));
	}
};
struct  MultiplicationCommand : public IBaseCommand
{
private:
	CalcProcessor* _proc = nullptr;
	int _x = 0;
	int _y = 0;
public:
	MultiplicationCommand(CalcProcessor* proc, int x, int y) {
		_proc = proc;
		_x = x;
		_y = y;
	}
	void Execute() {
		_proc->setBaseNumber(_proc->Multiplication(_x, _y));
	}

};
struct DivisionCommand : public IBaseCommand
{
private:
	CalcProcessor* _proc = nullptr;
	int _x = 0;
	int _y = 0;
public:
	DivisionCommand(CalcProcessor* proc, int x, int y) {
		_proc = proc;
		_x = x;
		_y = y;
	}
	void Execute() {
		_proc->setBaseNumber(_proc->Division(_x, _y));
	}

};
CalcProcessor* CalcProcessor::_processor = nullptr;

CalcProcessor* CalcProcessor::GetInstances() {

	if (_processor == nullptr) //only called upon once so no multiplce instances
	{
		_processor = new CalcProcessor();
	}

	return _processor;
}


wxString CalcProcessor::GiveOutput(wxString input) {
	string c(input.c_str()); //note to self this is the copy of the string inputed in since we don't want to change it. and I am writing this to you/myself
								// cause you will forget
	vector<int> nums;
	vector<string> signs;
	string deli = "+-X/"; //what you are checking for
	string negative = "(~)";
	int pos = 0;
	int pos2 = 0;
	while ((pos = c.find_first_of(deli)) != string::npos) {
		if (c[0] == '(')
		{
			while (pos2 = c.find_first_of(negative) != string::npos)
			{
				int number = stoi(c.substr(2, pos - 1));
				string s = c.substr(pos, 1);
				signs.push_back(s);
				nums.push_back(-number);
				c.erase(0, pos + 1);
			}
		}
		else
		{
			int number = stoi(c.substr(0, pos));
			string s = c.substr(pos, 1);
			signs.push_back(s);
			nums.push_back(number);
			c.erase(0, pos + 1);
		}
	}
	nums.push_back(stoi(c));

	int result = NULL;
	vector<IBaseCommand*> commands;
	if (nums.size() > 0)
	{
		if (nums.size() > 1) //if you are wondering why it looks like this the original code was suppose to be able to work with more than two number inputs
							//and I did not feel like reworking all of the code for only two inputs
		{
			for (size_t i = 0; i < signs.size(); i++)
			{
				if (signs[i] == "/")
				{
					DivisionCommand divide(this, nums[i], nums[i + 1]);
					commands.push_back(&divide);
				}
				else if (signs[i] == "+")
				{
					AddCommand add(this, nums[i], nums[i + 1]);
					commands.push_back(&add);
				}
				else if (signs[i] == "-")
				{
					SubtractCommand subtract(this, nums[i], nums[i + 1]);
					commands.push_back(&subtract);
				}
				else if (signs[i] == "X")
				{
					MultiplicationCommand mult(this, nums[i], nums[i + 1]);
					commands.push_back(&mult);
				}
			}
			for (size_t i = 0; i < commands.size(); i++)
			{
				commands[i]->Execute();
				result = baseNumber;
				commands.clear();
			}
		}
	}

	if (result < 0)
	{
		result *= -1;
		return "(~" + to_string(result) + ")";

	}
	else
	return to_string(result);
}

int CalcProcessor::Addition(int x, int y) {
	return x + y;
}
int CalcProcessor::Subtraction(int x,int y) {
	return x - y;
}
int CalcProcessor::Multiplication(int x, int y) {
	return x * y;
}
int CalcProcessor::Division(int x, int y) {
	return x / y;
}

void CalcProcessor::setBaseNumber(int number) {
	baseNumber = number;
}

string CalcProcessor::GetDecimal() {
	return to_string(baseNumber);
}

string CalcProcessor::GetBinary() {

	string result = "";
	int number = baseNumber;
	for (int i = 0; i < 16; i++) // 32 bit
	{
		if (number % 2 == 0)
		{
			result = "0" + result;
		}
		else
		{
			result = "1" + result;
		}
		number /= 2;
	}
	return result;
}

string CalcProcessor::GetHexadecimal() {

	string result = "";
	int num = baseNumber;
	while (num > 0)
	{
		int mod = num % 16;
		if (mod < 10)
		{
			result = to_string(mod) + result;
		}
		else if (mod >= 10)
		{
			char k = 'A' + mod - 10;
			result = k + result;
		}
		num = num / 16;
	}
	return "0x" + result;
}