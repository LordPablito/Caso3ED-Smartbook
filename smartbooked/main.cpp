#include <iostream>
#include "crow.h"
#include <vector>

// Estructura de datos para representar un libro
struct Book {
    std::string title;
    std::string author;
    int rating;
};

// Función para simular la búsqueda de libros
std::vector<Book> searchBooks(const std::string& query) {
    // Simulamos una búsqueda simple devolviendo una lista fija de libros
    return {
        {"Libro 1", "Autor 1", 5},
        {"Libro 2", "Autor 2", 4},
        {"Libro 3", "Autor 3", 3}
    };
}

int main() {
    crow::SimpleApp app;

    // Ruta que recibe la frase como parámetro y devuelve la lista de libros
    CROW_ROUTE(app, "/api/search/<string>")
    ([](const crow::request& req, std::string query) {
        // Realiza la búsqueda de libros con la frase proporcionada
        std::vector<Book> result = searchBooks(query);

        // Construye la respuesta JSON con la lista de libros y calificaciones
        crow::json::wvalue responseJson;
        for (const auto& book : result) {
            crow::json::wvalue bookJson;
            bookJson["title"] = book.title;
            bookJson["author"] = book.author;
            bookJson["rating"] = book.rating;
            responseJson["books"].push_back(bookJson);
        }

        // Devuelve la respuesta JSON
        return crow::response(responseJson);
    });

    // Configura el puerto y ejecuta la aplicación
    app.port(8080).multithreaded().run();

    return 0;
}
```

En este ejemplo:

- La ruta `/api/search/<string>` recibe la frase como un parámetro en la URL.
- La función `searchBooks` simula una búsqueda de libros basada en la frase proporcionada.
- La respuesta se construye como un objeto JSON que contiene la lista de libros y calificaciones.
- La aplicación Crow responde con este objeto JSON.

Para probar este servidor con Postman:

1. Ejecuta la aplicación.
2. Abre Postman y crea una solicitud GET a `http://localhost:8080/api/search/TuFraseAqui`.
3. Envía la solicitud y deberías recibir una respuesta con la lista simulada de libros y calificaciones basada en la frase que proporcionaste.

Este es un ejemplo básico que puedes adaptar según tus necesidades y la lógica de búsqueda real que desees implementar.