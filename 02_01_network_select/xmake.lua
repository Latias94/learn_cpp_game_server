target("02_01_network_select_app_client")
    set_kind("binary")
    add_files("src/apps/client/**.cpp")
    add_deps("02_01_network_select_network")

target("02_01_network_select_app_server")
    set_kind("binary")
    add_files("src/apps/server/**.cpp")
    add_deps("02_01_network_select_network")

target("02_01_network_select_network")
    set_kind("static")
    add_files("src/libs/network/**.cpp")
    add_includedirs("src/libs", {public = true})
    if is_plat("windows") then
        add_syslinks("Ws2_32")
    end
