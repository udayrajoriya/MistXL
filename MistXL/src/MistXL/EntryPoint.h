#pragma once

#ifdef MXL_PLATFORM_WINDOWS

extern MistXL::Application* MistXL::CreateApplication();

int main(int argc, char** argv)
{
	MistXL::Log::Init();
	MXL_CORE_WARN("Initialized Log!");
	int a = 47;
	MXL_INFO("Hello! Var={0}",a);

	auto app = MistXL::CreateApplication();
	app->Run();
	delete app;
}

#endif