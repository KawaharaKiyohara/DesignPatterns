#pragma once
class InputPersonalDataForm
{
	char address[256];	//�Z���B
	char name[256];		//���O�B
	int age;			//�N��B
public:
	InputPersonalDataForm();
	~InputPersonalDataForm();
	void Execute(int language);
private:
	//�Z������́B
	void InputAddress(int language);
	//�N�����́B
	void InputAge(int language);
	//���O����́B
	void InputName(int language);
};

