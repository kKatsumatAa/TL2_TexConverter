#include "TextureConverter.h"

using namespace DirectX;


void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//�t�@�C���p�X�����C�h������ɕϊ�
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	//WIC�e�N�X�`���̃��[�h(metadata��scratchImage�ɏ�񂪓���)
	auto result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int32_t filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

void TextureConverter::SeparateFilePath(const std::wstring& filePath)
{
}

//---------------------------------------------------------------------------
void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//�e�N�X�`���t�@�C����ǂݍ���
	LoadWICTextureFromFile(filePath);

	//DDS�`���ɕϊ����ď����o��

}
