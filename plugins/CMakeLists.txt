add_subdirectory(plugin1)

if (UNIX AND NOT APPLE)
    add_subdirectory(linuxplugin)
endif()