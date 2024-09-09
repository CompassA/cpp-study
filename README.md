#第三方库引入步骤

## 第三方库spdlog

下载&编译  
```bash
# 项目根目录执行, 下载代码
git submodule add -b v1.x --depth=1 git@github.com:gabime/spdlog.git third-parties/spdlog

# 编译
cd third-parties/spdlog && mkdir build && cd build
cmake .. && make -j
sudo make install
```

cmake引入  
```cpp
if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(example example.cpp)
target_link_libraries(example PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
```

## 第三方库 googtest

下载
```bash
git submodule add --depth=1 git@github.com:google/googletest.git third-parties/googletest
cd third-parties/googletest
git fetch --tags
git checkout v1.15.2

mkdir build && cd build
cmake .. && make -j
sudo make install
```  
  
vscode 安装c++ TestMate插件
