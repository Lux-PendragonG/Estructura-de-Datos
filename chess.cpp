#include <iostream>
#include <list>
using namespace std;

// Estructura para almacenar movimientos
struct Movimiento {
    int filaOrigen;
    int colOrigen;
    int filaDestino;
    int colDestino;
    char piezaMovida;
    char piezaCapturada;
};

class Ajedrez {
private:
    char tablero[8][8];
    list<Movimiento> historialMovimientos;

    bool esMovimientoValido(int filaOrig, int colOrig, int filaDest, int colDest) {
        char pieza = tablero[filaOrig][colOrig];
        
        // Verificar que la pieza pertenezca al jugador actual
        if (pieza == ' ') return false;
        
        // Verifica que el destino esté vacío o tenga una pieza enemiga
        return true;  // Simplificado para el ejemplo
    }

public:
    Ajedrez() {
        // Inicializar tablero
        // Piezas negras
        tablero[0][0] = 'R'; tablero[0][1] = 'N'; tablero[0][2] = 'B';
        tablero[0][3] = 'Q'; tablero[0][4] = 'K'; tablero[0][5] = 'B';
        tablero[0][6] = 'N'; tablero[0][7] = 'R';
        
        // Peones negros
        for(int i = 0; i < 8; i++) {
            tablero[1][i] = 'P';
        }
        
        // Espacios vacíos
        for(int i = 2; i < 6; i++) {
            for(int j = 0; j < 8; j++) {
                tablero[i][j] = ' ';
            }
        }
        
        // Peones blancos
        for(int i = 0; i < 8; i++) {
            tablero[6][i] = 'p';
        }
        
        // Piezas blancas
        tablero[7][0] = 'r'; tablero[7][1] = 'n'; tablero[7][2] = 'b';
        tablero[7][3] = 'q'; tablero[7][4] = 'k'; tablero[7][5] = 'b';
        tablero[7][6] = 'n'; tablero[7][7] = 'r';
    }

    void mostrarTablero() {
        cout << "  a b c d e f g h" << endl;
        for(int i = 0; i < 8; i++) {
            cout << 8-i << " ";
            for(int j = 0; j < 8; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << 8-i << endl;
        }
        cout << "  a b c d e f g h" << endl;
    }

    bool hacerMovimiento(int filaOrig, int colOrig, int filaDest, int colDest) {
        if (!esMovimientoValido(filaOrig, colOrig, filaDest, colDest)) {
            return false;
        }

        // Guardar el movimiento en el historial
        Movimiento mov;
        mov.filaOrigen = filaOrig;
        mov.colOrigen = colOrig;
        mov.filaDestino = filaDest;
        mov.colDestino = colDest;
        mov.piezaMovida = tablero[filaOrig][colOrig];
        mov.piezaCapturada = tablero[filaDest][colDest];

        historialMovimientos.push_back(mov);

        // Realizar el movimiento
        tablero[filaDest][colDest] = tablero[filaOrig][colOrig];
        tablero[filaOrig][colOrig] = ' ';

        return true;
    }

    void mostrarUltimoMovimiento() {
        if (!historialMovimientos.empty()) {
            Movimiento ultimo = historialMovimientos.back();
            cout << "Último movimiento: ";
            cout << (char)('a' + ultimo.colOrigen) << (8 - ultimo.filaOrigen) << " → ";
            cout << (char)('a' + ultimo.colDestino) << (8 - ultimo.filaDestino);
            cout << " (Pieza: " << ultimo.piezaMovida;
            if (ultimo.piezaCapturada != ' ') {
                cout << ", Capturó: " << ultimo.piezaCapturada;
            }
            cout << ")" << endl;
        }
    }
};

int main() {
    Ajedrez juego;
    string movimiento;
    char colOrig, colDest;
    int filaOrig, filaDest;

    while (true) {
        juego.mostrarTablero();
        cout << "\nIngrese movimiento (ejemplo: e2e4) o 'q' para salir: ";
        cin >> movimiento;

        if (movimiento == "q") break;

        if (movimiento.length() != 4) {
            cout << "Formato inválido. Use el formato 'e2e4'" << endl;
            continue;
        }

        colOrig = movimiento[0];
        filaOrig = '8' - movimiento[1];
        colDest = movimiento[2];
        filaDest = '8' - movimiento[3];

        // Convertir las columnas de letras a números (a=0, b=1, etc.)
        colOrig -= 'a';
        colDest -= 'a';

        if (juego.hacerMovimiento(filaOrig, colOrig, filaDest, colDest)) {
            cout << "\nMovimiento realizado:" << endl;
            juego.mostrarUltimoMovimiento();
        } else {
            cout << "\nMovimiento inválido. Intente de nuevo." << endl;
        }
    }

    return 0;
}