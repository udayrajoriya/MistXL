#include <MistXL.h>

class Sandbox : public MistXL::Application
{
	public:
		Sandbox()
		{

		}
		~Sandbox()
		{

		}
};

MistXL::Application* MistXL::CreateApplication()
{
	return new Sandbox();
}