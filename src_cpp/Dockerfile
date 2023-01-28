FROM ubuntu:22.04
#RUN apt update && apt -y install gpg
#RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
#RUN echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy-rc main' | tee -a /etc/apt/sources.list.d/kitware.list >/dev/null
##RUN apt-get update
##RUN rm /usr/share/keyrings/kitware-archive-keyring.gpg
##RUN apt update && apt -y install kitware-archive-keyring
##RUN apt-get update && apt-get -y install cmake
#RUN apt -y install cmake
RUN wget https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-linux-x86_64.sh -O cmake.sh
RUN sh cmake.sh --prefix=/usr/local/ --exclude-subdir
#RUN rm cmake.sh
WORKDIR /build