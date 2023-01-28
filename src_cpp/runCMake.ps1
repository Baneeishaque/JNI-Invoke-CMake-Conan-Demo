$env:PATH = 'C:/Users/dk/.conan/data/cmake/3.25.1/_/_/package/0a420ff5c47119e668867cdb51baff0eca1fdb68/bin;' + $env:PATH
$env:PATH = 'C:/Users/dk/.conan/data/ninja/1.11.1/_/_/package/0a420ff5c47119e668867cdb51baff0eca1fdb68/bin;' + $env:PATH
$env:PATH = 'C:\Programs\x86_64-12.2.0-release-win32-seh-msvcrt-rt_v10-rev2/bin;' + $env:PATH
cmake . -G Ninja
cmake --build .
.\src_cpp.exe
