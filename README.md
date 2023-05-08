* Создаем директории server и client
*
* В директории server создаем файлы: touch server.cpp и Dockerfile
*
* Запускаем сборку докера: docker build .
*
* docker ps - для просмотра активных контейнеров. Находим ID контейнера и копируем
*
* docker inspect <ID_container> - вывод содержимого контейнера - здесь находим IP_Adress контейнера по типу : "172.17.0.2"
*
* В директории client создаем файлы: touch client.cpp и Dockerfile
*
* Возврат в директорию, где хранятся директории server & client
*
* Создаем файл docker-compose.yml:
*
* version: "3.9"  - версия сборки, обычно не ниже 3
*
* services:
*  server:
*    build: ./server
*    ports:
*      - 5555:5555
*    networks:
*      - app-network
*
*  client:
*    build: ./client
*    ports:
*       - 5556:5556   - порт отличается с целью избежания конфликта сборки
*    depends_on:
*      - server
*    networks:
*      - app-network
*
* networks:
*   app-network:
*     driver: bridge   - некий мост связки
*
* egor@egor-120-1100er:~/TIMP-lab08$ docker-compose build    - сборка docker-compose
*
* egor@egor-120-1100er:~/TIMP-lab08$ docker-compose up     - запуск контейнера
*
* Creating network "timp-lab08_app-network" with driver "bridge"
* Recreating timp-lab08_server_1 ... done
* Recreating timp-lab08_client_1 ... done
* Attaching to timp-lab08_server_1, timp-lab08_client_1
* server_1  | Server listening on port 5555       - сервер вывел, что порт открылся и ожидает действий пользователя
*
* Для выхода и завершения работы сервера нажать CTRL + C
*
* Чтобы проверить работу контейнера в браузере необходимо ввести: localhost:<port_in_server_cpp>
*
*
* [Screenshot 2023-05-08 at 11-09-12 Screenshot](https://user-images.githubusercontent.com/113050829/236793188-6291a949-3718-4d9e-9616-ac4c8bc63077.png)
*
* Создаем директорию .github/workflows
*
* В ней прописываем CI.yml
*
* git add -A
* git commit -m ""
* git push origin main
*
*
*
*
*
