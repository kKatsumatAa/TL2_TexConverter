#include <cstdio>
#include <cstdlib>
#include<memory>

int main(uint32_t argc, char* argv[])
{
	//argc�̐��J��Ԃ�
	for (uint32_t i = 0; i < argc; i++)
	{
		//������argv��i�Ԃ�\��
		printf(argv[i]);
		//���s
		printf("\n");
	}

	system("pause");
	return 0;
}
