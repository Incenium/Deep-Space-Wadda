solution "game engine"
        configurations {"Debug", "Release"}

project "engine"
        kind "ConsoleApp"
        language "C"
        files {"src/*.c"}
        includedirs {"include"}
        buildoptions {"-std=c11"}
        links {"SDL2"}