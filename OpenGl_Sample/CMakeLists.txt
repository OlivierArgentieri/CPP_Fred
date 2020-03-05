# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Projects)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	.
	./
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)


# main
add_executable(

#base :
	main
	main/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	
#window :
	main/gameReseau/window/gr_window.hpp
	main/gameReseau/window/gr_window.cpp
	
#renderer :
	main/gameReseau/renderer/gr_renderer.hpp
	main/gameReseau/renderer/gr_renderer.cpp

#gameObject :
	main/gameReseau/gameObject/gr_gameObject.hpp
	main/gameReseau/gameObject/gr_gameObject.cpp

	main/gameReseau/gameObject/objgameObject/gr_objGameObject.hpp
	main/gameReseau/gameObject/objgameObject/gr_objGameObject.cpp
	
	main/gameReseau/gameObject/gameBoard/gr_gameBoard.hpp
	main/gameReseau/gameObject/gameBoard/gr_gameBoard.cpp
	
	main/gameReseau/gameObject/gameBoard/bottomBorder/gr_bottomBorderGameBoard.hpp
	main/gameReseau/gameObject/gameBoard/bottomBorder/gr_bottomBorderGameBoard.cpp
	
	main/gameReseau/gameObject/gameBoard/leftBorder/gr_leftBorderGameBoard.hpp
	main/gameReseau/gameObject/gameBoard/leftBorder/gr_leftBorderGameBoard.cpp
	
	main/gameReseau/gameObject/gameBoard/plane/gr_planeGameBoard.hpp
	main/gameReseau/gameObject/gameBoard/plane/gr_planeGameBoard.cpp
	
	main/gameReseau/gameObject/gameBoard/rightBorder/gr_rightBorderGameBoard.hpp
	main/gameReseau/gameObject/gameBoard/rightBorder/gr_rightBorderGameBoard.cpp
	
	main/gameReseau/gameObject/gameBoard/topBorder/gr_topBorderGameBoard.hpp
	main/gameReseau/gameObject/gameBoard/topBorder/gr_topBorderGameBoard.cpp
	
	main/gameReseau/gameObject/ball/gr_ball.hpp
	main/gameReseau/gameObject/ball/gr_ball.cpp
	

#color :
	main/gameReseau/color/gr_color.hpp
	main/gameReseau/color/gr_color.cpp
	
#transform :
	main/gameReseau/transform/gr_transform.hpp
	main/gameReseau/transform/gr_transform.cpp
	
	
#managers :
	main/gameReseau/managers/ball/gr_ballManager.hpp
	main/gameReseau/managers/ball/gr_ballManager.cpp
		
	main/gameReseau/managers/input/gr_inputManager.hpp
	main/gameReseau/managers/input/gr_inputManager.cpp

#util :
	main/gameReseau/util/gr_util.hpp
	main/gameReseau/util/gr_util.cpp

#player :
	main/gameReseau/player/gr_player.hpp
	main/gameReseau/player/gr_player.cpp

#time:
	main/gameReseau/time/gr_time.hpp
	main/gameReseau/time/gr_time.cpp

#shaders : 
	main/TransformVertexShader.vertexshader
	main/TextureFragmentShader.fragmentshader
)

target_link_libraries(main
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(main PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/main/")
create_target_launcher(main WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/main/")


SOURCE_GROUP(common  REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

SOURCE_GROUP(gameReseau\\window    REGULAR_EXPRESSION "./main/gameReseau/window/")

SOURCE_GROUP(gameReseau\\gameObject    REGULAR_EXPRESSION "./main/gameReseau/gameObject/")
SOURCE_GROUP(gameReseau\\gameObject\\objGameObject    REGULAR_EXPRESSION "./main/gameReseau/gameObject/objGameObject")
SOURCE_GROUP(gameReseau\\gameObject\\gameBoard    REGULAR_EXPRESSION "./main/gameReseau/gameObject/gameBoard")
SOURCE_GROUP(gameReseau\\gameObject\\gameBoard\\plane    REGULAR_EXPRESSION "./main/gameReseau/gameObject/gameBoard/plane")
SOURCE_GROUP(gameReseau\\gameObject\\gameBoard\\bottomBorder    REGULAR_EXPRESSION "./main/gameReseau/gameObject/gameBoard/bottomBorder")
SOURCE_GROUP(gameReseau\\gameObject\\gameBoard\\leftBorder    REGULAR_EXPRESSION "./main/gameReseau/gameObject/gameBoard/leftBorder")
SOURCE_GROUP(gameReseau\\gameObject\\gameBoard\\rightBorder    REGULAR_EXPRESSION "./main/gameReseau/gameObject/gameBoard/rightBorder")
SOURCE_GROUP(gameReseau\\gameObject\\gameBoard\\topBorder   REGULAR_EXPRESSION "./main/gameReseau/gameObject/gameBoard/topBorder")
SOURCE_GROUP(gameReseau\\gameObject\\ball REGULAR_EXPRESSION "./main/gameReseau/gameObject/ball/")
	
SOURCE_GROUP(gameReseau\\renderer    REGULAR_EXPRESSION "./main/gameReseau/renderer/")
SOURCE_GROUP(gameReseau\\color    REGULAR_EXPRESSION "./main/gameReseau/color/")
SOURCE_GROUP(gameReseau\\transform    REGULAR_EXPRESSION "./main/gameReseau/transform/")
SOURCE_GROUP(gameReseau\\managers\\ball REGULAR_EXPRESSION "./main/gameReseau/managers/ball")
SOURCE_GROUP(gameReseau\\managers\\input REGULAR_EXPRESSION "./main/gameReseau/managers/input")
SOURCE_GROUP(gameReseau\\util REGULAR_EXPRESSION "./main/gameReseau/util")
SOURCE_GROUP(gameReseau\\player REGULAR_EXPRESSION "./main/gameReseau/player")
SOURCE_GROUP(gameReseau\\time REGULAR_EXPRESSION "./main/gameReseau/time")


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
add_custom_command(
   TARGET main POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/main${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/main/"
)

elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

