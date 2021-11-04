#pragma once

#include "Core.h"

namespace MistXL
{
	class MISTXL_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	//To be defined in Client
	Application* CreateApplication();
}