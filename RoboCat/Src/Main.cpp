
#include "RoboCatPCH.h"
#include "allegro_wrapper_functions-main/GraphicsLibrary.h"

#if _WIN32


int main(int argc, const char** argv)
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);
#else
const char** __argv;
int __argc;
int main(int argc, const char** argv)
{
	__argc = argc;
	__argv = argv;
#endif

	GraphicsLibrary GL(1920.0, 1080.0);
	GL.init("background");

	SocketUtil::StaticInit();

	while (true)
	{
	}

	SocketUtil::CleanUp();

	return 0;
}
