//---------------------------------------------------------------------------

#ifndef UMatrizH
#define UMatrizH
//---------------------------------------------------------------------------

const int LONGMAX = 250;
class CMatriz {
	private:
		int fila;
		int columna;
		float matriz[LONGMAX][LONGMAX];
	public:
		CMatriz();
		void setFila(int valor);
		void setColumna(int valor);
		int getFila();
		int getColumna();
		void setElemento(int fila, int columna, float elemento);
		float getElemento(int fila, int columna);
		void eliminarFila(int fil);
		void eliminarColumna(int col);
		CMatriz *copiar(CMatriz *matrizCualquiera);
		CMatriz *subMatriz(int fil, int col);
		float elementoMasRepetido();
		void intercambiar(int fil1, int col1, int fil2, int col2);
		void intercambiarFilaColumna(int fil, int col);
		float sumarDiagonalSecundaria();
		bool  verificarMatrices(CMatriz *matrizA, CMatriz *matrizB);

};

#endif
