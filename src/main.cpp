#include "app.h"

i32 main(i32 argc, char** argv)
{
	auto app = new dd::App();
	return app->Run(argc, argv);
}
