workspace "RaylibPong"
	architecture "x86"
	configurations { "Debug", "Release"}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	
	
project "RaylibPong"
	location "RaylibPong"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"RaylibPong/vendor/imgui/**.h",
		"RaylibPong/vendor/imgui/**.cpp"
	}
	
	includedirs
	{
		"vendor/Raylib/include",
		"RaylibPong/vendor/imgui/include"
	}
	
	libdirs 
	{ 
		"vendor/Raylib/lib",
	}
	
	links { "raylib.lib", "Winmm.lib" }
	
	cppdialect "C++17"
	staticruntime "Off"
	systemversion "latest"
	
	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"