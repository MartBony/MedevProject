CMAKE_MINIMUM_REQUIRED( VERSION 3.0)

project ( MedevProject )

set(SRCS
	src/MedevProject.cpp
	src/Cell.cpp
	src/Grid.cpp
	src/Ship.cpp
)
	
set(HEADERS
	include/Cell.h
	include/Grid.h
	include/Ship.h
	)

add_executable( MedevProject ${SRCS} ${HEADERS} )

include_directories( include )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MedevProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
