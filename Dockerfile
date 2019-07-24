FROM ubuntu:18.04

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install g++ gcc make cmake pkg-config libhiredis0.13 libhiredis-dev

WORKDIR /code
COPY CMakeLists.txt .
COPY src/ src/

RUN mkdir build

WORKDIR /code/build
COPY samples/ samples/
RUN cmake ..
RUN make

CMD ["./log_parser"]
