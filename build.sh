# 下载库
echo "git submodule update start"
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

cd $root_path
cmake --build /home/dev/code/cpp-study/build --config Debug --target all -j 3 --

cp build/cppstudy cppstudy
./cppstudy