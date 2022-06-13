#include <Windows.h>
#include <crtdbg.h>
#include"KGClientModule/KGEngine.h"


int APIENTRY main(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char* p = new char[16];
	strcpy_s(p, 16, "_TestLeak_KG_");

	kg::KGEngine engine;

	if (!engine.Init(TEXT("KGClient"), hInstance, 1280, 720, 0, 0, true, true))
	{
		return 0;
	}


	int	iRet = engine.Run();

	return 0;
}