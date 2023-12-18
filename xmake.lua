set_project("LearnCppGameServer")
set_languages("c++20")
set_exceptions("cxx")

add_rules("mode.debug", "mode.release")

if is_plat("windows") then
    add_defines("MY_PLATFORM_WINDOWS")
elseif is_plat("linux") then
    add_defines("MY_PLATFORM_LINUX")
end

includes("**/xmake.lua")
