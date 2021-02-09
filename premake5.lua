workspace "Leezel"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Leezel"
    location "Leezel"
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
        systemversion "10.0.17134.0"

        defines
        {
            "LZ_BUILD_DLL",
            "LZ_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/".. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines "LZ_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "LZ_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "LZ_DIST"
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
        "Leezel/vendor/spdlog/include",
        "Leezel/src"
    }

    links
    {
        "Leezel"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17134.0"

        defines
        {
            "LZ_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "LZ_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "LZ_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "LZ_DIST"
            optimize "On"