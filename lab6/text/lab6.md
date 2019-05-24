# Лабораторная работа №6

## Задание 1

### Необходимые знания

1. TCP и TCP/IP  http://www.codenet.ru/webmast/tcpip.php
2. TCP vs UDP     http://www.codenet.ru/webmast/tcpip.php
1. Системный вызов `socket`   https://www.opennet.ru/man.shtml?topic=socket&category=2&russian=0
2. Системный вызов `bind`    https://www.opennet.ru/man.shtml?topic=bind&category=2&russian=0
2. Системный вызов `listen`  https://www.opennet.ru/man.shtml?topic=listen&category=2&russian=0
3. Системный вызов `accept`   https://www.opennet.ru/cgi-bin/opennet/man.cgi?topic=accept&category=2
4. Системный вызов `recv`  https://www.opennet.ru/man.shtml?topic=recv&category=2&russian=0
5. Системный вызов `send`   https://www.opennet.ru/man.shtml?topic=send&category=2&russian=0
6. Системный вызов `close`   https://www.opennet.ru/man.shtml?topic=close&category=2&russian=0
7. Системный вызов `connect`  https://www.opennet.ru/man.shtml?topic=connect&category=2&russian=0

hton (s, l ,т.п.) -преобразует uint16_t в набор байт для сетевого соединения (меняет местами байты)  https://www.opennet.ru/man.shtml?topic=htons&category=3&russian=0
INADDR_ANY = все адреса локального хоста (0.0.0.0);
https://www.opennet.ru/docs/RUS/socket/node4.html

setsockopt  -манипулирует флагами  https://www.opennet.ru/man.shtml?topic=setsockopt&category=2&russian=0

shutdown - уведомить об завершении подключения - https://www.opennet.ru/man.shtml?topic=shutdown&category=8&russian=2
//-----------------

В предыдущей лабораторной работе вы распаралелливали вычисление факториала по модулю с помощью потоков. В этой работе вы пойдете еще дальше: вы распараллелите эту работу еще и между серверами. 

Необходимо закончить `client.c` и `server.c`:

Клиент в качетсве аргументов командной сроки получает `k`, `mod`, `servers`, где `k` это факториал, который необходимо вычислить (`k! % mod`), `servers` это путь до файла, который содержит сервера (`ip:port`), между которыми клиент будет распараллеливать соединения.

Сервер получает от клиента "кусок" своих вычислений и `mod`, в ответ отсылает клиенту результат этих вычислений.

### Ресурсы

1. [Manual pages](http://man7.org/linux/man-pages/)
2. [TCP [Wikipedia]](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)

### Заметка

Обратите внимание, что клиент сейчас дожидается завершения работы с каждым сервером в цикле, т.е. последовательно. Это значит, что вам нужно подумать, как распараллелить работу с каждым сервером, чтобы сервера могли работать параллельно. Есть несколько вариантов, как это можно сделать, опираясь на уже пройденный вами материал, никто вас не ограничивает в выборе способа, но выбранный вариант вам необходимо объяснить.

## Задание 2

Создать makefile для программ клиента и сервера

## Задание 3

Найти дублирующийся код в двух приложениях и вынести его в библиотеку. Добавить изменения в makefile.

## Задание 4 (опционально)

Получить доступ из внешнего мира. Преподаватель может попросить вас объединиться с другим студентом, чтобы проденмонстрировать, как будет работать ваш сервер с чужим клиентом. Для этого в Codenvy зайдите в Servers (Dashboard->Workspace->Servers), добавьте порт, на котором будет висеть ваш сервер, презагрузите workspace на этой же вкладке браузера. Рядом с созданным "сервером" вы должны увидеть "белый" адрес, по которому вы можете обратиться к вашему серверу. 

## Перед тем, как сдавать

Залейте ваш код в ваш репозиторий на GitHub. Убедитесь, что вы не добавляете в репозиторий бинарные файлы (программы, утилиты, библиотеки и т.д.).
