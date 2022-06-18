#include "CalcProcessor.h"

CalcProcessor* CalcProcessor::_processor = nullptr;

CalcProcessor* CalcProcessor::GetInstances() {

	if (_processor == nullptr) //only called upon once so no multiplce instances
	{
		_processor = new CalcProcessor();
	}

	return _processor;
}


wxString CalcProcessor::GiveOutput(wxString input) {
	string c(input.c_str()); //note to self this is the copy of the string inputed in since we don't want to change it. and I am writing this to you
								// cause you will forget
	vector<int> nums;
	vector<string> signs;
	string deli = "+-X/"; //what you are checking for
	int pos = 0;
	while ((pos = c.find_first_of(deli)) != std::string::npos) {
		int number = stoi(c.substr(0, pos));
		string s = c.substr(pos, 1);
		signs.push_back(s);
		nums.push_back(number);
		c.erase(0, pos + 1);
	}
	nums.push_back(stoi(c));

	int result = NULL;
	if (nums.size() > 0)
	{
		result = nums[0];
		if (nums.size() > 1)
		{
			for (size_t i = 0; i < signs.size(); i++)
			{
				if (signs[i] == "/")
				{
					result = Division(result, nums[i + 1]);
				}
				else if (signs[i] == "+")
				{
					result = Addition(result, nums[i + 1]);
				}
				else if (signs[i] == "-")
				{
					result = Subtraction(result, nums[i + 1]);
				}
				else if (signs[i] == "X")
				{
					result = Multiplication(result, nums[i + 1]);
				}
			}
		}
	}

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