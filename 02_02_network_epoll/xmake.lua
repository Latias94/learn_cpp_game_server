target("02_02_network_epoll_app_robots")
    set_kind("binary")
    add_files("src/tools/robots/**.cpp")
    add_deps("02_02_network_epoll_network")

target("02_02_network_epoll_app_server")
    set_kind("binary")
    add_files("src/apps/server/**.cpp")
    add_deps("02_02_network_epoll_network")

target("02_02_network_epoll_network")
    set_kind("static")
    add_files("src/libs/network/**.cpp")
    add_includedirs("src/libs", {public = true})
    if is_plat("windows") then
        add_syslinks("Ws2_32")
    end
