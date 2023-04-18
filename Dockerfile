FROM ubuntu

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server/
COPY *.cpp /root/server/
COPY *.h /root/server/
COPY *.pro /root/server/

RUN qmake echoServer_332.pro
RUN make

EXPOSE 80/tcp
EXPOSE 80/udp
EXPOSE 33333/tcp
ENTRYPOINT ["./echoServer_332"]

#docker build .
#docker run -p 33333:80/tcp <hash-функция образа>
#С помощью команды узнаём id нашего контейнера и подключаемся к нему через putty