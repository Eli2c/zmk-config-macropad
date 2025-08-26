zephyr_include_directories(${ZMK_BASE}/app/include)

zephyr_library()
zephyr_library_sources(src/oled_display.c)
zephyr_library_include_directories(src)
zephyr_library_compile_definitions()
zephyr_library_link_libraries() 
