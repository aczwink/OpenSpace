set(SERVER_SOURCE_FILES
	${SERVER_SOURCE_FILES}

	#CLICommands
	${CMAKE_CURRENT_SOURCE_DIR}/CLICommands/Command.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CLICommands/ExitCommand.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CLICommands/HelpCommand.hpp

	#.
	${CMAKE_CURRENT_SOURCE_DIR}/CLI.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CLI.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/NetworkManager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/NetworkManager.hpp

	PARENT_SCOPE)