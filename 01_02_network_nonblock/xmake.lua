target("01_02_network_nonblock_app_client")
    set_kind("binary")
    add_files("src/apps/client/**.cpp")
    add_deps("01_02_network_nonblock_network")

target("01_02_network_nonblock_app_server")
    set_kind("binary")
    add_files("src/apps/server/**.cpp")
    add_deps("01_02_network_nonblock_network")

target("01_02_network_nonblock_network")
    set_kind("static")
    add_files("src/libs/network/**.cpp")
    add_includedirs("src/libs", {public = true})
    if is_plat("windows") then
        add_syslinks("Ws2_32")
    end
