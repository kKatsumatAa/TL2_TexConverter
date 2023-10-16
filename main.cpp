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

		NumArgument
	};


	//argcの数繰り返す
	for (uint32_t i = 0; i < argc; i++)
	{
		//文字列argvのi番を表示
		printf(argv[i]);
		//改行
		printf("\n");
	}
	
	assert(argc >= NumArgument);

	//comライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバーター
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//comライブラリの終了
	CoUninitialize();

	return 0;
}
