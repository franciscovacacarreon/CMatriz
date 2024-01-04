// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatriz.h"
#include "VCL.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

CMatriz::CMatriz() {
	fila = 0;
	columna = 0;
}

void CMatriz::setFila(int valor) {
	if (valor <= LONGMAX) {
		fila = valor;
	}
	else {
		ShowMessage("Longitud no v�lida");
	}
}

void CMatriz::setColumna(int valor) {
	if (valor <= LONGMAX) {
		columna = valor;
	}
	else {
		ShowMessage("Longitud no v�lida");
	}
}

int CMatriz::getFila() {
	return fila;
}

int CMatriz::getColumna() {
	return columna;
}

void CMatriz::setElemento(int fila, int columna, float elemento) {
	if (fila <= LONGMAX && columna <= LONGMAX) {
		matriz[fila][columna] = elemento;
	}
	else {
		ShowMessage("Longitud no v�lida");
	}
}

float CMatriz::getElemento(int fila, int columna) {
	float resultado = 0;
	if (fila <= LONGMAX && columna <= LONGMAX) {
		resultado = matriz[fila][columna]; // 15
	}
	else {
		ShowMessage("Longitud no v�lida");
	}
	return resultado;
}

void CMatriz::eliminarFila(int fil) {
	for (int i = fil; i < this->fila - 1; i++) {
		for (int j = 0; j < this->columna; j++) {
			matriz[i][j] = matriz[i + 1][j];
		}
	}
	this->fila--;
}

void CMatriz::eliminarColumna(int col) {
	for (int i = col; i < this->fila - 1; i++) {
		for (int j = 0; j < this->columna; j++) {
			matriz[j][i] = matriz[j][i + 1];
		}
	}
	this->columna--;
}

CMatriz *CMatriz::copiar(CMatriz *matrizCualquiera) {
	CMatriz *matrizR = new CMatriz();
	matrizR->setFila(matrizCualquiera->getFila());
	matrizR->setColumna(matrizCualquiera->getColumna());

	for (int i = 0; i < matrizR->getFila(); i++) {
		for (int j = 0; j < matrizR->getColumna(); j++) {
			float elemento = matrizCualquiera->getElemento(i, j);
			matrizR->setElemento(i, j, elemento);
		}
	}
	return matrizR;
}

CMatriz *CMatriz::subMatriz(int fil, int col) {
	CMatriz *matrizR = this->copiar(this);

	matrizR->eliminarFila(fil);
	matrizR->eliminarColumna(col);

	return matrizR;
}

float CMatriz::elementoMasRepetido() {
	int contador = 0;
	int mayorRepetido = 0;
	float elementoMasRepetido = 0;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			float elemento = matriz[i][j];
			contador = 0;

			for (int k = 0; k < fila; k++) {
				for (int h = 0; h < columna; h++) {
					if (elemento == matriz[k][h]) {
						contador++;
					}
				}
			}

			if (contador > mayorRepetido) {
				mayorRepetido = contador; // 2
				elementoMasRepetido = elemento;
			}
		}
	}

	return elementoMasRepetido;
}

void CMatriz::intercambiar(int fil1, int col1, int fil2, int col2) {
	float aux = matriz[fil1][col1];
	matriz[fil1][col1] = matriz[fil2][col2];
	matriz[fil2][col2] = aux;
}

void CMatriz::intercambiarFilaColumna(int fil, int col) {
	if (fila == columna) {
		for (int i = 0; i < fila; i++) {
			intercambiar(fil, i, i, col);
		}
	}
}

float CMatriz::sumarDiagonalSecundaria() {
	float sum = 0;
	if (fila == columna) { // matriz cuadrada
		int j = columna - 1;
		for (int i = 0; i < fila; i++) {
			sum = sum + matriz[i][j];
			j--;
		}
	}
	return sum;
}

bool CMatriz::verificarMatrices(CMatriz *matrizA, CMatriz *matrizB) {
	if (!(matrizA->getFila() == matrizB->getFila() &&
		matrizA->getColumna()== matrizB->getColumna())) {

		return false;
	}

	bool sw = true;
	for (int i = 0; i < matrizA->getFila() && sw == true; i++) {
		for (int j = 0; j < matrizA->getColumna() && sw == true; j++) {
			if (matrizA->getElemento(i, j) != matrizB->getElemento(i, j)) {
				sw = false;
			}
		}
	}
	return sw;
}
