add_rules("mode.debug")
add_rules("mode.release")
add_rules("mode.releasedbg")

function sources()
    add_files("src/**.c")
    add_headerfiles("src/**.h")
    add_sysincludedirs("include")

    if is_plat("windows") then
        add_defines("CSM_TARGET_WIN_GL=1")
    elseif is_plat("linux") then
        add_defines("CSM_TARGET_LINUX_GL=1")
    elseif is_plat("macosX") then
        add_defines("CSM_TARGET_MAC_GL=1")
    end
end

target("live2d-freecore")
    set_kind("shared")
    sources()

target("live2d-freecore-static")
    set_kind("static")
    sources()

target("live2d-freecore-test")
    set_kind("binary")
    sources()
