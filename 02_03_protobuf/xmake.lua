add_requires("protobuf-cpp")

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
    add_files("src/libs/network/protobuf/*.proto", {rules = "protobuf.cpp", proto_rootdir = "02_03_protobuf/src/libs/network/protobuf", proto_public = true, proto_autogendir = path.join(os.projectdir(), ".")})
    add_includedirs("src/libs", {public = true})
    add_packages("protobuf-cpp", {public = true})
    if is_plat("windows") then
        add_syslinks("Ws2_32")
    end
    if is_plat("linux") then
        add_defines("EPOLL", {public = true})
    end
