#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg); // Выводит сообщение об ошибке и завершает программу
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n"); // Выводит сообщение об ошибке, если не указан порт
        exit(1);
    }5

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket"); // Создает соксет с помощью системного вызова socket и проверяет на ошибку

    bzero((char *) &serv_addr, sizeof(serv_addr)); // Обнуляет структуру serv_addr

    portno = atoi(argv[1]);
    if (portno <= 0) {
        fprintf(stderr, "ERROR, invalid port number provided\n"); // Выводит сообщение об ошибке, если указан недопустимый порт
        exit(1);
    }

    serv_addr.sin_family = AF_INET; // Устанавливает семейство адресов на IPv4
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Устанавливает адрес сервера на "любой доступный"
    serv_addr.sin_port = htons(portno); // Устанавливает порт сервера и конвертирует его в сетевой порядок байт

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding"); // Привязывает соксет к адресу и порту, проверяет на ошибку

    listen(sockfd, 5); // Устанавливает соксет в режим прослушивания с очередью длиной 5

    clilen = sizeof(cli_addr);

    printf("Waiting for a connection on port %d...\n", portno); // Выводит сообщение ожидания соединения на указанном порту
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); // Принимает входящее соединение и создает новый соксет для общения с клиентом
    if (newsockfd < 0)
        error("ERROR on accept"); // Проверяет на ошибку при принятии соединения

    printf("Connection established with a client.\n"); // Выводит сообщение о установленном соединении с клиентом

    bzero(buffer, 256); // Обнуляет буфер

    n = read(newsockfd, buffer, 255); // Считывает данные из соксета
    if (n < 0)
        error("ERROR reading from socket"); // Проверяет на ошибку при чтении данных

    printf("Here is the message: %s\n", buffer); // Выводит принятое сообщение
    fprintf(stderr, "%d bytes\n", n); // Выводит количество принятых байт

    n = write(newsockfd, "I got your message", 18); // Отправляет ответное сообщение клиенту
    if (n < 0)
        error("ERROR writing to socket"); // Проверяет на ошибку при записи данных

    close(newsockfd); // Закрывает соксет для общения с клиентом
    close(sockfd); // Закрывает основной соксет, слушающий входящие соединения
    printf("Connection closed and server terminating.\n"); // Выводит сообщение о закрытии соединения и завершении сервера

    return 0;
}
