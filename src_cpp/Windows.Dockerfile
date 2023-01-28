FROM mcr.microsoft.com/windows:10.0.17763.3887-amd64

# ARG cmakeDownloadUrl="https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-linux-x86_64.sh"
# ARG conanDownloadUrl="https://github.com/conan-io/conan/releases/latest/download/conan-ubuntu-64.deb"

# RUN apt update \
#  && apt install -y wget \
#  && rm -rf /var/lib/apt/lists/*

# RUN wget ${cmakeDownloadUrl} \
#  && cmakeInstallationFile=$(basename ${cmakeDownloadUrl}) \
#  && sh $cmakeInstallationFile --prefix=/usr/local/ --exclude-subdir \
#  && rm $cmakeInstallationFile

# RUN wget ${conanDownloadUrl} \
#  && apt update \
#  && apt install -y \
#      ./conan-ubuntu-64.deb \
#  && rm -rf /var/lib/apt/lists/* \
#  && rm conan-ubuntu-64.deb

# RUN conan profile new default --detect \
#  && conan profile update settings.compiler.libcxx=libstdc++11 default

# WORKDIR /src_cpp