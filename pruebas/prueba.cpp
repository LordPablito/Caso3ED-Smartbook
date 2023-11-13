#include <iostream>
#include <cpr/cpr.h>

int main() {
    // Hacer la solicitud GET
    auto response = cpr::Get(cpr::Url{"https://random-word-form.repl.co/random/noun"});

    // Verificar si la solicitud fue exitosa
    if (response.status_code == 200) {
        // Mostrar la palabra generada
        std::cout << "Palabra generada: " << response.text << std::endl;
    } else {
        // Mostrar un mensaje en caso de error
        std::cerr << "Error al obtener la palabra. Código de estado: " << response.status_code << std::endl;
    }

    return 0;
}