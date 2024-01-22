#pragma once
#include<string>
#include<Windows.h>
// DirectXテクスチャライブラリを使用できるようにする
#include <DirectXTex.h>

//テクスチャコンバーター
class TextureConverter
{
private:
	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;


private:
	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// マルチバイト文字列をワイド文字列に変換
	/// </summary>
	/// <param name="mString">マルチバイト文字列</param>
	/// <returns>ワイド文字列</returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

private:
	/// <summary>
	/// フォルダパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

public: 
	/// <summary>
	/// テクスチャをwicからddsに変換
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);
};