set(HDRS
        model.h
        mainccd.h
)

set(SRCS
        mainTorusknot.cpp
        model.cpp
)

configure_file(../tri_models/bunny_noholes.tri bunny_noholes.tris COPYONLY)
configure_file(../models/torusknot2.ani torusknot2.ani COPYONLY)
add_executable(mainTorusknot ${SRCS})
target_link_libraries(mainTorusknot PRIVATE PQP freeglut_static C2A::C2A)