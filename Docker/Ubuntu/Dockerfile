FROM ubuntu:latest

WORKDIR /home/docker_env

ENTRYPOINT rm -rf build && /bin/bash

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    libudev-dev \
    pkg-config \
    libgl-dev \
    xorg-dev \
    libx11-xcb-dev  \
    libxcb-render0-dev \
    libxcb-render-util0-dev \
    libxcb-xkb-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-randr0-dev \
    libxcb-shape0-dev \
    libxcb-sync-dev \
    libxcb-xfixes0-dev \
    libxcb-xinerama0-dev \
    xkb-data \
    libxcb-dri3-dev \
    libxcb-util-dev \
    make    \
    python3-pip \
    cmake

RUN pip3 install conan && pip3 install conan --upgrade

