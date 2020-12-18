FROM alpine:latest

USER root
RUN apk add gcc g++ make cmake

COPY . /app
WORKDIR /app

USER root
RUN cmake . -Bbuild -Wdev -Werror=dev
RUN cmake --build ./build
WORKDIR /app/build
CMD ["ctest"]
