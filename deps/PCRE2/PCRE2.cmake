prusaslicer_add_cmake_project(PCRE2
    URL https://github.com/PCRE2Project/pcre2/archive/3103b8f20a3b9944b177e812fde29fbfb8b90558.zip
    URL_HASH SHA256=0c8c7e68973fdd5fea38ef8e83412832511f9c2f8e2968e6d98df4bb29df1221
    CMAKE_ARGS
        -DCMAKE_INSTALL_LIBDIR=lib # workaround on centos7
        -DPCRE2_STATIC_PIC:BOOL=ON
        -DPCRE2_BUILD_TESTS:BOOL=OFF
)