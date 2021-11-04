#pragma once

#ifdef MXL_PLATFORM_WINDOWS

extern MistXL::Application* MistXL::CreateApplication();

int main(int argc, char** argv)
{
	auto app = MistXL::CreateApplication();
	app->Run();
	delete app;
}

#endif