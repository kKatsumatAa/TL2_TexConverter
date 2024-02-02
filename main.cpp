#include <cstdio>
#include <cstdlib>
#include<memory>
#include<cassert>
#include<Windows.h>
#include"TextureConverter.h"

int main(uint32_t argc, char* argv[])
{
	//コマンドライン引数
	enum Argument 
	{
		kApplicationPath,//アプリケーションのパス
		kFilePath,//渡されたファイルのパス

		NumArgument//引数文字列への添え字
	};


	//argcの数繰り返す
	for (uint32_t i = 0; i < argc; i++)
	{
		//文字列argvのi番を表示
		printf(argv[i]);
		//改行
		printf("\n");
	}
	
	//コマンドライン引数指定なし
	if (argc < NumArgument)
	{
		//使い方を表示
		TextureConverter::OutputUsage();
		return 0;
	}

	//comライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバーター
	TextureConverter converter;

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列（ダブルポインタ）
	char** options = argv + NumArgument;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath],numOptions,options);

	//comライブラリの終了
	CoUninitialize();

	return 0;
}
