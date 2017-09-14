workspace "Project Nebula"
  configurations {"Debug32", "Release32", "Debug64", "Release64"}
  location "build"
  filter "configurations:*32"
    architecture "x86"
  filter "configurations:*64"
    architecture "x86_64"
  configuration "vs*"
    defines { "_CRT_SECURE_NO_WARNINGS" }
  filter "configurations:Debug32"
    targetdir "bin/x86/Debug"
    defines { "DEBUG" }
    debugenvs { "PATH=%PATH%;../engine/lib/SDL2/bin/x86/Debug;../engine/lib/SDL2_gfx/bin/x86/Debug;../engine/lib/SDL2_Image/bin/x86/Debug;../engine/lib/SDL2_ttf/bin/x86"}
    symbols "On"
  filter "configurations:Release32"
    targetdir "bin/x86/Release"
    defines { "NDEBUG" }
    optimize "On"
  filter "configurations:Debug64"
    targetdir "bin/x64/Debug"
    defines { "DEBUG" }
    symbols "On"
  filter "configurations:Release64"
    targetdir "bin/x64/Release"
    defines { "NDEBUG" }
    optimize "On"
project "Wolfheart Engine"
  kind "StaticLib"
  language "C++"
  files { "engine/include/**.h", "engine/src/**.cpp"}
  includedirs {
    "engine/include",
    "engine/include/**",
    "engine/lib/SDL2/include",
    "engine/lib/SDL2_Image/include",
    "engine/lib/SDL2_ttf/include",
    "engine/lib/SDL2_gfx/include",
    "engine/lib/Box2D/include",
    "engine/lib/Box2D/include/**"
  }
  configuration "vs*"
    characterset "MBCS"
  configuration "Debug32"
    libdirs {
      "engine/lib/SDL2/bin/x86/Debug",
      "engine/lib/SDL2_Image/bin/x86/Debug",
      "engine/lib/SDL2_gfx/bin/x86/Debug",
      "engine/lib/SDL2_ttf/bin/x86",
      "engine/lib/Box2D/bin/x86/Debug"
    }
    links {
      "Box2D",
      "SDL2",
      "SDL2main",
      "SDL2_gfx",
      "SDL2_image",
      "SDL2_ttf"
    }
project "Project Nebula Client"
  kind "WindowedApp"
  language "C++"
  files { "src/**.h", "src/**.cpp" }
  includedirs {
    "engine/include",
    "engine/include/**",
    "engine/lib/SDL2/include",
    "engine/lib/SDL2_Image/include",
    "engine/lib/SDL2_ttf/include",
    "engine/lib/SDL2_gfx/include",
    "engine/lib/Box2D/include",
    "engine/lib/Box2D/include/**"
  }

  configuration "vs*"
    characterset "MBCS"
  configuration "Debug32"
    libdirs {
      "bin/x86/Debug",
      "engine/lib/SDL2/bin/x86/Debug",
      "engine/lib/SDL2_Image/bin/x86/Debug",
      "engine/lib/SDL2_gfx/bin/x86/Debug",
      "engine/lib/SDL2_ttf/bin/x86",
      "engine/lib/Box2D/bin/x86/Debug"
    }
    links {
      "Wolfheart Engine"
    }
project "Project Nebula World Server"
  kind "ConsoleApp"
  language "C++"
  files { "worldserver/**.h", "worldserver/**.cpp"}
project "Project Nebula Login Server"
  kind "ConsoleApp"
  language "C++"
  files { "loginserver/**.h", "loginserver/**.cpp" }
