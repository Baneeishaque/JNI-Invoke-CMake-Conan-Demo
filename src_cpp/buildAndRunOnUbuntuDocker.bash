docker build -t baneeishaque/jni_invoke_cmake_conana_demo . && docker run -v "$(pwd)":/src_cpp -t baneeishaque/jni_invoke_cmake_conana_demo bash -c "cmake . && cmake --build . && ./bin/src_cpp"