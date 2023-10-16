#include <cstdio>
#include <cstdlib>
#include<memory>
#include<cassert>
#include<Windows.h>
#include"TextureConverter.h"

int main(uint32_t argc, char* argv[])
{
	//�R�}���h���C������
	enum Argument 
	{
		kApplicationPath,//�A�v���P�[�V�����̃p�X
		kFilePath,//�n���ꂽ�t�@�C���̃p�X

		NumArgument
	};


	//argc�̐��J��Ԃ�
	for (uint32_t i = 0; i < argc; i++)
	{
		//������argv��i�Ԃ�\��
		printf(argv[i]);
		//���s
		printf("\n");
	}
	
	assert(argc >= NumArgument);

	//com���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^�[
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//com���C�u�����̏I��
	CoUninitialize();

	return 0;
}
