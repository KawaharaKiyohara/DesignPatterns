// TemplateMethodPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputPersonalDataForm.h"

int main()
{
	int language = 0;
	printf("�����I��ł��������B0:���{��A1:�p��\n");
	scanf_s("%d", &language);
	if (language == 0 || language == 1) {
		//�l�����̓t�H�[�������s����B
		InputPersonalDataForm inputPersonalDataForm;

		inputPersonalDataForm.Execute(language);
	}
	else {
		printf("�I�����ꂽ���ꂪ�s���ł��B\n");
	}
    return 0;
}

