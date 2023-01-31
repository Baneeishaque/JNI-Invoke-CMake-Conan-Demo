docker build -t baneeishaque/jni_invoke_cmake_conana_demo .; if ($?)
{
    docker run -v "$( Get-Location ):/src_cpp" -v "$( Get-Location )/.conan:/root/.conan" -t baneeishaque/jni_invoke_cmake_conana_demo bash -c "cmake . && cmake --build . && ./bin/src_cpp"
}
