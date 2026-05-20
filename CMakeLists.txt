cmake_minimum_required(VERSION 4.2)
project(nonogramme C)

set(CMAKE_C_STANDARD 11)

add_executable(nonogramme main.c
        console/console.c
        console/console.h
        console/console-internal.h

        repository/nonogramfile.c
        repository/nonogramfile.h

        service/nonogrammeservice.c
        service/nonogrammeservice.h

        entity/dimension.c
        entity/dimension.h
        entity/dimension-internal.h

        entity/grid.c
        entity/grid.h
        entity/grid-internal.h

        entity/constraints.c
        entity/constraints.h
        entity/constraints-internal.h

        entity/constraint.c
        entity/constraint.h
        entity/constraint-internal.h

        entity/pixel.c
        entity/pixel.h
        entity/pixel-internal.h

        entity/nonogram.c
        entity/nonogram.h
        entity/nonogram-internal.h
)
