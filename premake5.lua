workspace "MistXL"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MistXL"
	location "MistXL"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MXL_PLATFORM_WINDOWS",
			"MXL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MXL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MXL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MXL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"MistXL/vendor/spdlog/include",
		"MistXL/src"
	}

	links
	{
		"MistXL"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MXL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MXL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MXL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MXL_DIST"
		optimize "On"