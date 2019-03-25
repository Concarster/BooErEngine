workspace "BooEr"

     architecture "x86"
     architecture "x64"

     startproject "BooErGame"

     filter "system:windows"
		disablewarnings { "4996", "4251" }
                  
platforms {       -- Dropdown Solution Confg Platforms section in VS
    
     "Win32",
     "x64"
} 
    
configurations {   -- Dropdown Solution Configurations
     "Debug",
     "Release"  
}

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"


project "BooErEngine" 
    location "BooErEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("bint/" .. outputdir .. "/%{prj.name}")

pchheader "booPCH.h"
pchsource "BooErEngine/src/booPCH.cpp"

    files {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",

    }

    includedirs {

        "%{prj.name}/src"
    }

    links { 

		"opengl32.lib"
	}

    filter"system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
             "BOO_ENGINE",
             "BOO_WINDOW",
             "BOO_BUILD_DLL",
             "GLFW_INCLUDE_NONE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/BooErGame/\"")
        }

        filter "configurations:Debug"
        buildoptions "/MDd"
        defines "DEBUG"
        symbols "On"

        filter "configurations:Release"
        buildoptions "/MD"
        defines "RELEASE"
        optimize "On"


-----------------------------------
-----     PROJECT # 1 BooErGame     -----
-----------------------------------

project "BooErGame" 
    location "BooErGame"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bint/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {

        "BooErEngine/src"
    }

  

    links {
        "BooErEngine",
		"opengl32.lib"
    }

    filter"system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
             "BOO_ENGINE",
             "BOO_WINDOW"
        }


        filter "configurations:Debug"
        buildoptions "/MDd"
        defines "DEBUG"
        symbols "On"

        filter "configurations:Release"
        buildoptions "/MD"
        defines "RELEASE"
        optimize "On"
