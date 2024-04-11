cmake_minimum_required(VERSION 3.0.2)
project(UDP_TEST)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(udp_sender_node src/udp_sender.cpp src/simple_udp.cpp)
target_link_libraries(udp_sender_node ${catkin_LIBRARIES})

add_executable(udp_receiver_node src/udp_receiver.cpp src/simple_udp.cpp)
target_link_libraries(udp_receiver_node ${catkin_LIBRARIES})
