FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

# Enable man pages
# RUN rm /etc/dpkg/dpkg.cfg.d/excludes && \
#     apt-get update && \
#     dpkg -l | grep ^ii | cut -d' ' -f3 | xargs apt-get install -y --reinstall && \
#     rm -r /var/lib/apt/lists/* 

RUN apt-get -y update && \
    dpkg -l | grep ^ii | cut -d' ' -f3 | grep -v '^libgcc-s1:amd64$' | xargs apt-get install -y --reinstall && \
    rm -r /var/lib/apt/lists/* 

# Install Required Tools
RUN rm /var/lib/apt/lists/* -vfR && \
    apt-get update && \
    apt-get install -y vim wget curl tar git bash-completion software-properties-common \
                        apt-file apt-utils bc cmake man nano rpm telnet tree traceroute \
                        sudo

# Install GCC, GDB, Python3
RUN apt-get update && \
    apt-get upgrade && \
    apt-get install -y gcc gdb python3 python3-pip libpython3-dev

# Update
RUN rm /var/lib/apt/lists/* -vfR && \
    apt-get update && \
    apt-get upgrade -y &&\
    apt-get dist-upgrade -y

RUN rm -rf /tmp/*

RUN yes | unminimize

# Finishing Up
RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u 1000 -p $(openssl passwd -1 password) ubuntu
USER ubuntu
RUN echo PS1="'${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\W\[\033[00m\]\$ '" >> ~/.bashrc && \
    echo "alias la='ls -la'" >> ~/.bashrc && \
    echo "clear" >> ~/.bashrc && \
    mkdir /home/ubuntu/.trash
WORKDIR /home/ubuntu/workspace

# Command to build
# docker build --tag lp-lab --file docker/Dockerfile .