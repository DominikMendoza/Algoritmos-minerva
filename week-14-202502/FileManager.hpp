#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
class FileManager
{
private:
	ofstream writer;
	ifstream reader;

public:
	FileManager();
	~FileManager();
	string leerDeTxt(string route);
	void escribirEnTxt(string route, string mensaje);
	void leerValoresDeEjercicio(int& X, int& Y, int& N, int& T, string route);
};

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

string FileManager::leerDeTxt(string route)
{
	string contenido, linea;

	reader.open(route);

	if (!reader.is_open()) {
		cout << "Error al abrir el archivo...\n";
		return "";
	}

	while (getline(reader, linea))
	{
		contenido += linea + "\n";
	}

	reader.close();
	return contenido;
}

void FileManager::escribirEnTxt(string route, string mensaje)
{
	writer.open(route);
	if (!writer.is_open()) {
		cout << "Error al abrir el archivo...\n";
	}

	writer << mensaje;
	writer.close();
}

void FileManager::leerValoresDeEjercicio(int& X, int& Y, int& N, int& T, string route)
{
	string resultado = leerDeTxt(route);
	if (resultado.empty()) {
		// escribir el archivo txt
		return;
	}
	
	char aux;
	stringstream ss(resultado);
	
	ss >> aux >> aux >> X;
	ss >> aux >> aux >> Y;
	ss >> aux >> aux >> N;
	ss >> aux >> aux >> T;
}
