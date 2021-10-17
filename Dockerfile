FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive
ENV TERM=xterm

RUN apt update && \
    apt install -yq --no-install-recommends apt-utils && \
    apt install -yq build-essential parallel cmake git libgmp3-dev libmpfr-dev zlib1g zlib1g-dev bc wget python3 python3-pip gcc-10 g++-10 ncurses-term && \
    python3 -m pip install --upgrade pip && \
    python3 -m pip install matplotlib && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /home

####################################################################
# Move soplex 4.0.1 and build it
####################################################################
COPY soplex-4.0.1.tgz /home/soplex.tgz
RUN tar -xvf soplex.tgz && \
    cd soplex-4.0.1/ && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    cd ../..

ENV SOPLEXPATH=/home/soplex-4.0.1/
ENV ICCPATH=/opt/intel/oneapi/

####################################################################
# git clone popl2022artifact
####################################################################
RUN git clone https://github.com/jpl169/POPL2022Artifact.git && \
    cd POPL2022Artifact && \
    make

WORKDIR /home/POPL2022Artifact

