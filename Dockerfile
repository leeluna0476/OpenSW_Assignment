FROM ubuntu:latest

RUN apt update && apt install sudo adduser -y
RUN useradd -m -d /home/leeluna0476 leeluna0476

WORKDIR /home/leeluna0476/OpenSW_Assignment
CMD [ "bash" ]
