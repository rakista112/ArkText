local imgui_dir = "../imgui"
local ark_dir = "../myArk"
local sfml_dir = "../SFML-2.5.1"
local imgui_sfml_dir = "../imgui-sfml"
workspace "ArkSpace"
    configurations { "Debug", "Release" }
    location "build"
    architecture "x64"

project "imgui"
    kind "StaticLib"
    language "C++"
    includedirs { imgui_dir, sfml_dir .. "/include", imgui_sfml_dir }
    files {  imgui_dir .. "/*.h", imgui_dir .. "/*.cpp"}

project "Ark"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	defines {"NOSHOWWINDOW"}
	libdirs { ark_dir .. "/build/Debug" }
	includedirs { 	ark_dir .. "/include",
					ark_dir .. "/submodules/String/include",
					ark_dir .. "/thirdparties"}
	links { "ArkReactor" }

project "ArkText"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
    targetdir "build/bin/%{cfg.buildcfg}"
    dependson {"imgui", "Ark"}
    libdirs {sfml_dir .. "/lib", ark_dir .. "/build/Debug"}
    links {"imgui", "sfml-system", "sfml-window", "sfml-graphics", "ArkReactor", "opengl32"}

    includedirs {  imgui_dir, imgui_sfml_dir,
                    sfml_dir .. "/include",
					ark_dir .. "/include",
					ark_dir .. "/submodules/String/include",
					ark_dir .. "/thirdparties",
					"include/**"}

    files { imgui_dir .. "**.cpp", "**.h", "**.cpp"}
    location "build/ArkText"
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

    