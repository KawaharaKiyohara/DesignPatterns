#include "stdafx.h"
#include "InputPersonalDataForm.h"


//�R���X�g���N�^�B
InputPersonalDataForm::InputPersonalDataForm()
{
	//�R���X�g���N�^�ŏ���������B
	memset(address, 0, sizeof(address));
	memset(name, 0, sizeof(name));
	age = 0;
}

//�f�X�g���N�^�B
InputPersonalDataForm::~InputPersonalDataForm()
{
}

//�Z������́B
void InputPersonalDataForm::InputAddress(int language)
{
	if (language == 0) {
		//���{��
		printf("�Z������͂��Ă��������B\n");
		scanf_s("%s", address, 256);
	}
	else if (language == 1) {
		//�p��
		printf("Please enter your address.\n");
		scanf_s("%s", address, 256);
	}
}
//�N�����́B
void InputPersonalDataForm::InputAge(int language)
{
	if (language == 0) {
		//���{��
		printf("�N�����͂��Ă��������B\n");
		scanf_s("%d", &age);
	}
	else if (language == 1) {
		//�p��
		printf("Please enter your age.\n");
		scanf_s("%d", &age);
	}
}
//���O����́B
void InputPersonalDataForm::InputName(int language)
{
	if (language == 0) {
		//���{��
		printf("���O����͂��Ă��������B\n");
		scanf_s("%s", name, 256);
	}
	else if (language == 1) {
		//�p��
		printf("Please enter your name.\n");
		scanf_s("%s", name, 256);
	}
}

//�l�����͂̎��s�B
void InputPersonalDataForm::Execute(int language)
{
	InputAddress(language);
	InputName(language);
	InputAge(language);
	
	printf("---------------------------\n");
	printf("%s\n%s\n%d\n", address, name, age);
	printf("---------------------------\n");
}