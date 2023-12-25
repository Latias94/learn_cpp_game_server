target("02_03_protobuf_app_robots")
    set_kind("binary")
    add_files("src/tools/robots/**.cpp")
    add_deps("02_03_protobuf_network")

target("02_03_protobuf_app_server")
    set_kind("binary")
    add_files("src/apps/server/**.cpp")
    add_deps("02_03_protobuf_network")

target("02_03_protobuf_network")
    set_kind("static")
    add_files("src/libs/network/**.cpp")
    add_includedirs("src/libs", {public = true})
    if is_plat("windows") then
        add_syslinks("Ws2_32")
    end
    if is_plat("linux") then
        add_defines("EPOLL", {public = true})
    end
