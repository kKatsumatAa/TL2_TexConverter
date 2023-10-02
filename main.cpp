#include <cstdio>
#include <cstdlib>
#include<memory>

int main(uint32_t argc, char* argv[])
{
	//argc‚Ì”ŒJ‚è•Ô‚·
	for (uint32_t i = 0; i < argc; i++)
	{
		//•¶š—ñargv‚Ìi”Ô‚ğ•\¦
		printf(argv[i]);
		//‰üs
		printf("\n");
	}

	system("pause");
	return 0;
}
