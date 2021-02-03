FROM ubuntu:focal

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG DEBIAN_FRONTEND=noninteractive

RUN echo "deb http://mirrors.ustc.edu.cn/ubuntu/ focal main restricted universe multiverse\n\
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-security main restricted universe multiverse\n\
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-updates main restricted universe multiverse\n\
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-backports main restricted universe multiverse\n" \
    > /etc/apt/sources.list \
    && apt-get -y -q update \
    && apt-get -y -q upgrade \
    && apt-get -y -q install build-essential git clang clang-tidy clang-format clangd lldb \
    && groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*
