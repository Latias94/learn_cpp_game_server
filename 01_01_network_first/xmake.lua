target("01_01_network_first_app_client")
    set_kind("binary")
    add_files("src/apps/client/**.cpp")
    add_deps("01_01_network_first_network")

target("01_01_network_first_app_server")
    set_kind("binary")
    add_files("src/apps/server/**.cpp")
    add_deps("01_01_network_first_network")

target("01_01_network_first_network")
    set_kind("static")
    add_files("src/libs/network/**.cpp")
    add_includedirs("src/libs", {public = true})
    if is_plat("windows") then
        add_syslinks("Ws2_32")
    end
