FROM docker.io/qmkfm/base_container:latest

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        gcc \
        g++ \
        gcc-avr \
        avr-libc \
        cpputest \
        make \
        pkg-config \
        avrdude \
        minicom \
    && rm -rf /var/lib/apt/lists/* 

RUN pip install qmk && \
    qmk setup -y -H /qmk_firmware

WORKDIR /qmk_firmware

CMD ["/bin/bash"]