/************************************************
 * PROYECTO 1
 * FECHA: 12-02-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: COMANDOS.CPP
 ***********************************************/
#include <iostream>
#include "comandos.h"
#include "clases.h"
#include <fstream>

using namespace std;
/*Creamos una clase de tipo Imagen*/
Imagen imagen;
bool cargadaI = false;
Volumen volumen;
bool cargadaV = false;



/*Funcion que veifica si el archivo existe*/
bool archivoExiste(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();
}

/*Funcion para cargar una imagen*/
void cargarImagen(const std::vector<std::string>& argumentos) {
    if (!archivoExiste(argumentos[1])) {
        std::cout << "Error: El archivo no existe.\n";
        return;
    }
    std::ifstream archivo(argumentos[1]);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return;
    }
    //std::cout << "Se ha ingresado la imagen: " << argumentos[1] << ".\n";
    std::string codigo;
    int xTamano, yTamano, maxIntensidad;

    // Leer el encabezado
    archivo >> codigo >> xTamano >> yTamano >> maxIntensidad;

    // Configurar el objeto Imagen
    imagen.setNombre(argumentos[1]);
    imagen.setCodigo(codigo);
    imagen.setXTamano(xTamano);
    imagen.setYTamano(yTamano);
    imagen.setMaxIntensidad(maxIntensidad);

    // Leer los píxeles y almacenarlos en la lista de listas
    std::list<std::list<int>> listaPixeles;
    for (int y = 0; y < yTamano; ++y) {
        std::list<int> fila;
        for (int x = 0; x < xTamano; ++x) { // *3 porque cada píxel tiene R, G y B
            int valor;
            archivo >> valor;
            fila.push_back(valor);
        }
        listaPixeles.push_back(fila);
    }

    imagen.setLista(listaPixeles);
    cargadaI = true;
    archivo.close();

    //std::cout << "Tamano de la lista en X: " << imagen.getLista().front().size() << std::endl;
    //std::cout << "Tamano de la lista: " << imagen.getLista().size() << " yTamano: " << imagen.getYTamano() << std::endl;
    if(imagen.getLista().size() != imagen.getYTamano()){
        std::cout << "Error: El archivo no tiene el tamano correcto de Columnas.\n";
        return;
    }
    std::cout << "La imagen " << argumentos[1] << " ha sido cargada.\n";
}

/*Funcion para cargar un volumen*/
void cargarVolumen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> cargar_volumen <nombre_base> <n_im>\n";
        return;
    }
    std::string nombre;
    std::vector<std::string> argumentosI;
    std::string nombreBase = argumentos[1];
    int nImagenes = std::stoi(argumentos[2]);
    bool todasExisten = true;
    std::list<Imagen> lImagenes;

    std::string ultimos22 = nombreBase.erase(0, 15);
    if (ultimos22.size() > 15) {
        ultimos22.erase(ultimos22.size() - 4, 4); // Elimina los últimos 4 caracteres
    }else {
        ultimos22.erase(ultimos22.size() - 3, 3); // Elimina los últimos 4 caracteres
    }
    for (int i= 1; i <= nImagenes; i++) {
        //std::cout << "Valor de i: " << i << std::endl;
        // Construye el nombre del archivo con dos dígitos (01, 02, ..., 10, etc.)
        std::string numeroImagen = (i < 10) ? "0" + std::to_string(i) : std::to_string(i); // Asegura que los números de 1 dígito tengan un 0 al inicio
        std::string nombreArchivo = "imagenesPrueba/" + nombreBase + "/" + ultimos22 + numeroImagen + ".ppm";
        //std::cout << "NOMBRE DEL ARCHIVO: " << nombreArchivo << std::endl;
        if (!archivoExiste(nombreArchivo)) {
            std::cout << "Error: El archivo " << nombreArchivo << " no existe.\n";
            todasExisten = false;
        }

        argumentosI.push_back("vacio");
        argumentosI.push_back(nombreArchivo);
        cargarImagen(argumentosI);
        lImagenes.push_back(imagen);
        argumentosI.clear();

    }
    cargadaV = true;
    cargadaI = false;
    if (todasExisten) {
        std::cout << "El volumen " << nombreBase << " ha sido cargado.\n";
    } else {
        std::cout << "Error: No se pudo cargar el volumen debido a archivos faltantes.\n";
        return;
    }
    volumen.setNombre(nombreBase);
    volumen.setNImagenes(nImagenes);
    volumen.setLista(lImagenes);
}

//Funcion para mostrar la informacion de la imagen cargada en memoria
void infoImagen() {
    if(!cargadaI){
        std::cout << "Error: No hay ninguna imagen cargada en memoria.\n";
        return;
    }
    std::cout << "Imagen cargada en memoria: " << imagen.getNombre() << ", ancho: " << imagen.getXTamano() <<", alto: " << imagen.getYTamano() <<".\n";
}
//Funcion para mostrar la informacion del volumen cargado en memoria
void infoVolumen() {
    if(!cargadaV){
        std::cout << "Error: No hay ningun volumen cargado en memoria.\n";
        return;
    }
    std::cout << "Volumen cargado en memoria: " << volumen.getNombre() << ", Tamano: " << volumen.getNImagenes() << ".\n";
}

//funcion para la proyeccion 2D
void proyeccion2D(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 4) {
        std::cout << "Error: Uso correcto -> proyeccion2D <direccion> <criterio> <nombre_archivo.pgm>\n";
        return;
    }

    if (!cargadaV) {
        std::cout << "El volumen aún no ha sido cargado en memoria.\n";
        return;
    }

    if (volumen.getLista().empty()) {
        std::cerr << "Error: La lista de volumen está vacía.\n";
        return;
    }

    std::string direccion = argumentos[1];
    std::string criterio = argumentos[2];
    std::string nombreArchivo = argumentos[3];

    // Validar criterio
    if (criterio != "minimo" && criterio != "maximo" && criterio != "promedio" && criterio != "mediana") {
        std::cout << "Error: Criterio no valido. Use minimo, maximo, promedio, o mediana.\n";
        return;
    }

    // Validar dirección
    if (direccion != "x" && direccion != "y" && direccion != "z") {
        std::cout << "Error: Dirección no válida. Use x, y, o z.\n";
        return;
    }

    // Obtener dimensiones del volumen
    int ancho = volumen.getLista().front().getXTamano();
    int alto = volumen.getLista().front().getYTamano();
    int profundidad = volumen.getNImagenes();

    // Estructura para almacenar la proyección 2D
    std::list<std::list<int>> proyeccion;

    if (direccion == "x") {
        // Proyección en X: Colapsar columnas (eje X)
        for (int y = 0; y < alto; y++) {
            std::list<int> fila;
            for (int z = 0; z < profundidad; z++) {
                auto imagen = volumen.getLista().begin();
                std::advance(imagen, z);
                auto filaImagen = imagen->getLista().begin();
                std::advance(filaImagen, y);

                if (criterio == "minimo") {
                    int minimo = 255;
                    for (int valor : *filaImagen) {
                        if (valor < minimo) minimo = valor;
                    }
                    fila.push_back(minimo);
                } else if (criterio == "maximo") {
                    int maximo = 0;
                    for (int valor : *filaImagen) {
                        if (valor > maximo) maximo = valor;
                    }
                    fila.push_back(maximo);
                } else if (criterio == "promedio") {
                    int suma = 0;
                    for (int valor : *filaImagen) {
                        suma += valor;
                    }
                    fila.push_back(suma / ancho);
                } else if (criterio == "mediana") {
                    std::vector<int> valores(filaImagen->begin(), filaImagen->end());
                    std::sort(valores.begin(), valores.end());
                    fila.push_back(valores[valores.size() / 2]);
                }
            }
            proyeccion.push_back(fila);
        }
    } else if (direccion == "y") {
        // Proyección en Y: Colapsar filas (eje Y)
        for (int x = 0; x < ancho; x++) {
            std::list<int> fila;
            for (int z = 0; z < profundidad; z++) {
                auto imagen = volumen.getLista().begin();
                std::advance(imagen, z);
                int suma = 0;
                int minimo = 255;
                int maximo = 0;
                std::vector<int> valores;

                for (auto filaImagen : imagen->getLista()) {
                    auto it = filaImagen.begin();
                    std::advance(it, x);
                    int valor = *it;

                    if (criterio == "minimo") {
                        if (valor < minimo) minimo = valor;
                    } else if (criterio == "maximo") {
                        if (valor > maximo) maximo = valor;
                    } else if (criterio == "promedio") {
                        suma += valor;
                    } else if (criterio == "mediana") {
                        valores.push_back(valor);
                    }
                }

                if (criterio == "minimo") {
                    fila.push_back(minimo);
                } else if (criterio == "maximo") {
                    fila.push_back(maximo);
                } else if (criterio == "promedio") {
                    fila.push_back(suma / alto);
                } else if (criterio == "mediana") {
                    std::sort(valores.begin(), valores.end());
                    fila.push_back(valores[valores.size() / 2]);
                }
            }
            proyeccion.push_back(fila);
        }
    } else if (direccion == "z") {
        // Proyección en Z: Colapsar profundidad (eje Z)
        for (int y = 0; y < alto; y++) {
            std::list<int> fila;
            for (int x = 0; x < ancho; x++) {
                int suma = 0;
                int minimo = 255;
                int maximo = 0;
                std::vector<int> valores;

                for (int z = 0; z < profundidad; z++) {
                    auto imagen = volumen.getLista().begin();
                    std::advance(imagen, z);
                    auto filaImagen = imagen->getLista().begin();
                    std::advance(filaImagen, y);
                    auto it = filaImagen->begin();
                    std::advance(it, x);
                    int valor = *it;

                    if (criterio == "minimo") {
                        if (valor < minimo) minimo = valor;
                    } else if (criterio == "maximo") {
                        if (valor > maximo) maximo = valor;
                    } else if (criterio == "promedio") {
                        suma += valor;
                    } else if (criterio == "mediana") {
                        valores.push_back(valor);
                    }
                }

                if (criterio == "minimo") {
                    fila.push_back(minimo);
                } else if (criterio == "maximo") {
                    fila.push_back(maximo);
                } else if (criterio == "promedio") {
                    fila.push_back(suma / profundidad);
                } else if (criterio == "mediana") {
                    std::sort(valores.begin(), valores.end());
                    fila.push_back(valores[valores.size() / 2]);
                }
            }
            proyeccion.push_back(fila);
        }
    }

    // Guardar la proyección en un archivo PGM
    guardarPGM(proyeccion, nombreArchivo);
    std::cout << "La proyeccion 2D del volumen en memoria ha sido generada y almacenada en el archivo " << nombreArchivo << ".\n";
}

//Funcion para guardar la proyeccion en un archivo
void guardarPGM(const std::list<std::list<int>>& proyeccion, const std::string& nombreArchivo) {
    //std::cout << "Intentando guardar el archivo: " << nombreArchivo << "\n";
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "La proyección 2D del volumen en memoria no ha podido ser generada.\n";
        return;
    }
    
    archivo << "P2\n" << proyeccion.front().size() << " " << proyeccion.size() << "\n255\n"; //Se ingresa en el archivo el tamaño en e X y luego el tamoño en Y
    for (const auto& fila : proyeccion) {
        for (int valor : fila) {
            archivo << valor << " ";
        }
        archivo << "\n";
    }
    archivo.close();
}

//Funcion para codificar imagenes
void codificarImagen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 2) {
        std::cout << "Error: Uso correcto -> codificar_imagen <nombre_archivo.pgm>\n";
        return;
    }
    if (!cargadaI) {
        std::cout << "Error: No hay ninguna imagen cargada en memoria.\n";
        return;
    }
    
    vector<unsigned long> freq(256, 0);
    for (const auto& fila : imagen.getLista()) {
        for (int valor : fila) {
            freq[valor]++;
        }
    }
    HuffmanTree tree(freq);
    map<unsigned char, string> codes = tree.getCodes();
    vector<unsigned char> pixels; //(imagen.getXTamano() * imagen.getYTamano());

    unsigned short xTamano = static_cast<unsigned short>(imagen.getXTamano());
    unsigned short yTamano = static_cast<unsigned short>(imagen.getYTamano());
    unsigned short maxIntensidad = static_cast<unsigned short>(imagen.getMaxIntensidad());
    
    ofstream out(argumentos[1], ios::binary);
    out.write(reinterpret_cast<char*>(&xTamano), sizeof(unsigned short));
    out.write(reinterpret_cast<char*>(&yTamano), sizeof(unsigned short));
    out.write(reinterpret_cast<char*>(&maxIntensidad), sizeof(unsigned short));
    for (int i = 0; i <= imagen.getMaxIntensidad(); i++) {
        out.write(reinterpret_cast<char*>(&freq[i]), sizeof(unsigned long));
    }

    string bitStream;
    for(auto it = imagen.getLista().begin(); it != imagen.getLista().end(); ++it) {
        for (int valor : *it) {
            pixels.push_back(static_cast<unsigned char>(valor));
        }
    }
    for (unsigned char pixel : pixels) {
        bitStream += codes[pixel];
    }
    
    // Contar los bits válidos en el bitStream antes de agregar ceros extra
    size_t numBitsValidos = bitStream.size();

    while (bitStream.size() % 8 != 0) {
        bitStream += "0";
    }

    for (size_t i = 0; i < bitStream.size(); i += 8) {
        bitset<8> byte(bitStream.substr(i, 8));
        unsigned char byteVal = static_cast<unsigned char>(byte.to_ulong());
        out.write(reinterpret_cast<char*>(&byteVal), sizeof(unsigned char));
    }

    // Guardar el número de bits válidos al final del archivo
    out.write(reinterpret_cast<char*>(&numBitsValidos), sizeof(size_t));
    
    out.close();
    std::cout << "La imagen ha sido codificada y almacenada en " << argumentos[1] << ".\n";
}

//Funcion para decodificar un archivo
void decodificarArchivo(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> decodificar_archivo <nombre_archivo.pgm> <nombre_imagen.pgm>\n";
        return;
    }
    ifstream in(argumentos[1], ios::binary);
    if (!in) {
        cerr << "El archivo" << argumentos[1] << "no ha podido ser decodificado." << endl;
        return;
    }
    
    unsigned short xTamano, yTamano;
    unsigned short maxIntensidad;
    in.read(reinterpret_cast<char*>(&xTamano), sizeof(unsigned short));
    in.read(reinterpret_cast<char*>(&yTamano), sizeof(unsigned short));
    in.read(reinterpret_cast<char*>(&maxIntensidad), sizeof(unsigned char));
    
    vector<unsigned long> freq(256, 0);
    for (int i = 0; i <= maxIntensidad; i++) {
        in.read(reinterpret_cast<char*>(&freq[i]), sizeof(unsigned long));
    }

    bool freqValida = false;
    for (auto f : freq) {
        if (f > 0) {
            freqValida = true;
            break;
        }
    }
    if (!freqValida) {
        cerr << "Error: No se pudo reconstruir el árbol de Huffman.\n";
        return;
    }
    
    HuffmanTree tree(freq);
    HuffmanNode* root = tree.getRoot();
    HuffmanNode* current = root;
    
    vector<unsigned char> pixels;
    // Leer todos los bytes del archivo
    vector<unsigned char> bytes;
    char byte;
    while (in.read(&byte, sizeof(char))) {
        bytes.push_back(static_cast<unsigned char>(byte));
    }

    // Leer el número de bits válidos que fue guardado al final
    size_t numBitsValidos;
    if (bytes.size() < sizeof(size_t)) {
        cerr << "Error: Archivo corrupto o incompleto.\n";
        return;
    }
    memcpy(&numBitsValidos, &bytes[bytes.size() - sizeof(size_t)], sizeof(size_t));
    bytes.resize(bytes.size() - sizeof(size_t));

    // Eliminar los bytes usados para guardar `numBitsValidos`
    bytes.resize(bytes.size() - sizeof(size_t));

    // Convertir bytes a un string binario
    string bitStream;
    for (unsigned char b : bytes) {
        bitStream += bitset<8>(b).to_string();
    }

    // Recortar el bitStream para que tenga solo los bits válidos
    bitStream = bitStream.substr(0, numBitsValidos);
    in.close();
    
    for (char bit : bitStream) {
        if (bit == '0') current = current->left;
        else current = current->right;
        
        if (!current->left && !current->right) {
            pixels.push_back(current->pixel);
            current = root;
        }
    }
    
    ofstream out(argumentos[2]);
    out << "P3\n" << xTamano << " " << yTamano << "\n" << (int)maxIntensidad << "\n";
    for (unsigned char pixel : pixels) {
        out << (int)pixel << " ";
    }
    out.close();    
    std::cout << "El archivo " << argumentos[1] << " ha sido decodificado y almacenado en " << argumentos[2] << ".\n";
}

//Funcion para segmentar 
void segmentar(const std::vector<std::string>& argumentos) {
    if (argumentos.size() < 3) {
        std::cout << "Error: Uso correcto -> segmentar <salida_imagen.pgm> <semillas>\n";
        return;
    }
    std::cout << "La imagen ha sido segmentada y almacenada en " << argumentos[1] << ".\n";
}