// TemplateMethodPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputPersonalDataForm.h"

int main()
{
	int language = 0;
	printf("言語を選んでください。0:日本後、1:英語\n");
	scanf_s("%d", &language);
	if (language == 0 || language == 1) {
		//個人情報入力フォームを実行する。
		InputPersonalDataForm inputPersonalDataForm;

		inputPersonalDataForm.Execute(language);
	}
	else {
		printf("選択された言語が不正です。\n");
	}
    return 0;
}

