#include "stdafx.h"
#include "InputPersonalDataForm.h"


//コンストラクタ。
InputPersonalDataForm::InputPersonalDataForm()
{
	//コンストラクタで初期化する。
	memset(address, 0, sizeof(address));
	memset(name, 0, sizeof(name));
	age = 0;
}

//デストラクタ。
InputPersonalDataForm::~InputPersonalDataForm()
{
}

//住所を入力。
void InputPersonalDataForm::InputAddress(int language)
{
	if (language == 0) {
		//日本語
		printf("住所を入力してください。\n");
		scanf_s("%s", address, 256);
	}
	else if (language == 1) {
		//英語
		printf("Please enter your address.\n");
		scanf_s("%s", address, 256);
	}
}
//年齢を入力。
void InputPersonalDataForm::InputAge(int language)
{
	if (language == 0) {
		//日本語
		printf("年齢を入力してください。\n");
		scanf_s("%d", &age);
	}
	else if (language == 1) {
		//英語
		printf("Please enter your age.\n");
		scanf_s("%d", &age);
	}
}
//名前を入力。
void InputPersonalDataForm::InputName(int language)
{
	if (language == 0) {
		//日本語
		printf("名前を入力してください。\n");
		scanf_s("%s", name, 256);
	}
	else if (language == 1) {
		//英語
		printf("Please enter your name.\n");
		scanf_s("%s", name, 256);
	}
}

//個人情報入力の実行。
void InputPersonalDataForm::Execute(int language)
{
	InputAddress(language);
	InputName(language);
	InputAge(language);
	
	printf("---------------------------\n");
	printf("%s\n%s\n%d\n", address, name, age);
	printf("---------------------------\n");
}