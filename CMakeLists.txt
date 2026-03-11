cmake_minimum_required(VERSION 3.15)
project(CStarterProject LANGUAGES C)

# Standard: C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Clang-Tidy Integration
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
  set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE}")
else()
  message(WARNING "clang-tidy not found")
endif()

# Sanitizer Options
option(USE_ASAN "Enable AddressSanitizer" OFF)
option(USE_TSAN "Enable ThreadSanitizer" OFF)

if(USE_ASAN AND USE_TSAN)
  message(FATAL_ERROR "ASan and TSan cannot be enabled at the same time")
endif()

if(USE_ASAN)
  add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
  add_link_options(-fsanitize=address)
endif()

if(USE_TSAN)
  add_compile_options(-fsanitize=thread)
  add_link_options(-fsanitize=thread)
endif()

# Compilation Flags
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Werror -Wpedantic)
endif()

enable_testing()

add_library(unified_diff_parser src/unified_diff_parser.c)
target_include_directories(unified_diff_parser PUBLIC include)

add_executable(unified_diff_tests tests/unified_diff_tests.c)
target_link_libraries(unified_diff_tests PRIVATE unified_diff_parser)

add_executable(unified_diff_example examples/unified_diff_example.c)
target_link_libraries(unified_diff_example PRIVATE unified_diff_parser)

add_test(NAME unified_diff_tests COMMAND unified_diff_tests)

