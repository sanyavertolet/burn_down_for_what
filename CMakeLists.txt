cmake_minimum_required(VERSION 3.23)
project(burn_down_for_what)

set(CMAKE_CXX_STANDARD 20)

set(
        solvers
        src/Randomizer/Randomizer.cpp
        src/Randomizer/Randomizer.h
        src/SASolver/AbstractSASolver/AbstractSASolver.h
)

set(
        temperatures
        src/TemperatureDecreaser/AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.cpp
        src/TemperatureDecreaser/AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.h
        src/TemperatureDecreaser/BoltzmannTemperatureDecreaser/BoltzmannTemperatureDecreaser.cpp
        src/TemperatureDecreaser/BoltzmannTemperatureDecreaser/BoltzmannTemperatureDecreaser.h
        src/TemperatureDecreaser/CauchyTemperatureDecreaser/CauchyTemperatureDecreaser.cpp
        src/TemperatureDecreaser/CauchyTemperatureDecreaser/CauchyTemperatureDecreaser.h
        src/TemperatureDecreaser/MixedTemperatureDecreaser/MixedTemperatureDecreaser.cpp
        src/TemperatureDecreaser/MixedTemperatureDecreaser/MixedTemperatureDecreaser.h
)

set(
        solutions
        src/Solution/AbstractSASolution/AbstractSASolution.h
        src/Solution/SchedulingSASolution/SchedulingSASolution.cpp
        src/Solution/SchedulingSASolution/SchedulingSASolution.h
)

set(
        mutators
        src/Mutator/AbstractMutator/AbstractMutator.h
        src/Mutator/SchedulingMutator/SchedulingMutator.h
        src/Mutator/SchedulingMutator/SchedulingMutator.cpp
)

add_executable(burn_down_for_what main.cpp ${solvers} ${temperatures} ${solutions} ${mutators})
