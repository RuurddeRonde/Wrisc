workspace "Wrisc"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Wrisc/vendor/GLFW/include"
IncludeDir["GLAD"] = "Wrisc/vendor/GLAD"
IncludeDir["ImGui"] = "Wrisc/vendor/imgui"
IncludeDir["DuckX"] = "Wrisc/vendor/DuckX-master"

group "Dependencies"
	include "Wrisc/vendor/GLFW"
	include "Wrisc/vendor/GLAD"
	include "Wrisc/vendor/imgui"
	include "Wrisc/vendor/DuckX-master"

project "Wrisc"
	location "Wrisc"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.DuckX}",
	}
	links 
	{ 
		"DuckX",
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "WRISC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WRISC_RELEASE"
		optimize "On"