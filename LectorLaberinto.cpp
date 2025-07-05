#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream archivo("lamberintoTenochtitlan2.txt");

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    vector<string> laberinto;
    string linea;
    while (getline(archivo, linea)) {
        laberinto.push_back(linea);
    }
    archivo.close();

    // Definimos las coordenadas iniciales del agente
    int posX = 1;
    int posY = 2;
     
     
    char comando;
    do {
        // Mostrar el laberinto con el agente
        for (int y = 0; y < laberinto.size(); y++) {
            for (int x = 0; x < laberinto[y].size(); x++) {
                if (x == posX && y == posY) {
                    cout << '*';  // Mostrar al agente
                } else {
                    cout << laberinto[y][x];
                }
            }
            cout << endl;
        }

        cout << "\nUsa WASD para mover (w=arriba, s=abajo, a=izquierda, d=derecha), q para salir: ";
        cin >> comando;

        int nuevoX = posX;
        int nuevoY = posY;

        switch (comando) {
            case 'w': nuevoY--; break;
            case 's': nuevoY++; break;
            case 'a': nuevoX--; break;
            case 'd': nuevoX++; break;
        }

        // Verificar que no se salga del laberinto ni pase paredes
        if (nuevoY >= 0 && nuevoY < laberinto.size() &&
            nuevoX >= 0 && nuevoX < laberinto[nuevoY].size() &&
            laberinto[nuevoY][nuevoX] != '|'
			laberinto[nuevoY][nuevoX] != '_'){   // Suponiendo que '#' son paredes
            posX = nuevoX;
            posY = nuevoY;
            
        }

        system("cls");  // Limpia la pantalla en Windows (usa "clear" en Linux/Mac)
    } while (comando != 'q');

    cout << "Juego terminado." << endl;

    return 0;
}

