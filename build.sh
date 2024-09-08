# 下载库
echo "git submodule update start"

git submodule init
git submodule update

# 编译
root_path=$(pwd)
libnames=$(ls third-parties)
for libname in $libnames
do
    cd $root_path/third-parties/$libname
    if [ ! -d "build" ]; then
        echo "init lib $libname"
        mkdir build
        cd build
        cmake .. 
        make -j
        sudo make install
        cd ..
    fi
    cd $root_path/third-parties
done