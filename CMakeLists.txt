CMAKE_MINIMUM_REQUIRED( VERSION 3.0)

project ( MedevProject )

file(GLOB_RECURSE
	SRCS
	src/*
)

# set(SRCS
#	src/MedevProject.cpp
#	src/Cell.cpp
#	src/Grid.cpp
#	src/Ship.cpp
#)
	

add_executable( MedevProject ${SRCS})

include_directories( include )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MedevProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
