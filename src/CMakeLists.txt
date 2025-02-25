add_library(General General.cpp)
target_include_directories(General PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(Clock Clock.cpp)
target_include_directories(Clock PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(LinearMotion LinearMotion.cpp)
target_link_libraries(LinearMotion Clock)
target_include_directories(LinearMotion PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(NoticeRound NoticeRound.cpp)
target_link_libraries(NoticeRound LinearMotion)
target_include_directories(NoticeRound PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(Controller Controller.cpp)
target_include_directories(Controller PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(BoardGame BoardGame.cpp)
target_link_libraries(BoardGame Controller Clock General)
target_include_directories(BoardGame PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(Button Button.cpp)
target_link_libraries(Button Controller)
target_include_directories(Button PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(RoundedButton RoundedButton.cpp)
target_link_libraries(RoundedButton Button)
target_include_directories(Button PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(ImageButton ImageButton.cpp)
target_link_libraries(ImageButton Button)
target_include_directories(ImageButton PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(DynamicBox DynamicBox.cpp)
target_link_libraries(DynamicBox Controller LinearMotion General)
target_include_directories(DynamicBox PUBLIC ${CMAKE_SOURCE_DIR}/include)


add_library(Form Form.cpp)
target_include_directories(Form PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(Menu Menu.cpp)
target_link_libraries(Menu Form RoundedButton DynamicBox)
target_include_directories(Menu PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(GameForm GameForm.cpp)
target_link_libraries(GameForm Form ImageButton BoardGame NoticeRound)
target_include_directories(GameForm PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(Application Application.cpp)
target_link_libraries(Application Menu Form GameForm)
target_include_directories(Application PUBLIC  ${CMAKE_SOURCE_DIR}/include)


