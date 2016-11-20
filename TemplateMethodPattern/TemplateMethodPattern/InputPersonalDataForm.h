#pragma once
class InputPersonalDataForm
{
	char address[256];	//住所。
	char name[256];		//名前。
	int age;			//年齢。
public:
	InputPersonalDataForm();
	~InputPersonalDataForm();
	void Execute(int language);
private:
	//住所を入力。
	void InputAddress(int language);
	//年齢を入力。
	void InputAge(int language);
	//名前を入力。
	void InputName(int language);
};

