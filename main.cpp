#include <cstdio>
#include <cstdlib>
#include<memory>

int main(uint32_t argc, char* argv[])
{
	//argcの数繰り返す
	for (uint32_t i = 0; i < argc; i++)
	{
		//文字列argvのi番を表示
		printf(argv[i]);
		//改行
		printf("\n");
	}

	system("pause");
	return 0;
}
