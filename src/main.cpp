#include "app.hpp"

i32 main(i32 argc, char** argv)
{
	auto app = new didi::App();
	return app->Run(argc, argv);
}
