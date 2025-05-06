ARG DISTR

# Container image that runs your code
FROM $DISTR

ARG USER_ID
ARG GROUP_ID

RUN apt-get update \
    && apt-get install -y git \
    gear \
    rpm-utils \
    rpm-build \
    rpm-build-licenses \
    rpm-macros-cmake \
    rpm-macros-make \
    rpm-macros-generic-compat \
    apt-repo \
    apt-repo-tools \
    cmake \
    rpm-macros-cmake \
    cmake-modules \
    gcc \
    gcc-c++ \
    qt5-base-devel \
    qt5-base-common \
    libhttp-parser-devel \
    && export CURRENT_PWD=`pwd` \
    && groupadd --gid $GROUP_ID builder2 \
    && useradd --uid $USER_ID --gid $GROUP_ID -ms /bin/bash builder2 \
    && mkdir /app \
    && chown builder2:builder2 /app

USER root

RUN chmod a=rwx,u+t /tmp

# Copies your code file from your action repository to the filesystem path `/` of the container
COPY script/build.sh /build.sh

USER builder2
WORKDIR /home/builder2

# Code file to execute when the docker container starts up (`build.sh`)
ENTRYPOINT ["/build.sh"]
